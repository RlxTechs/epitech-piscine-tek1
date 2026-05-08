import json
import sys
from http.server import BaseHTTPRequestHandler, HTTPServer
from pathlib import Path
from urllib.parse import urlparse

from src.api_logic import (
    health,
    list_products,
    add_product,
    list_orders,
    add_order,
    demo_operations,
)


ROOT = Path(__file__).resolve().parent
DB_PATH = ROOT / "data" / "db.json"
HOST = "localhost"
PORT = 8080


def print_json(data: dict) -> None:
    print(json.dumps(data, ensure_ascii=False, indent=2))


class LocalApiHandler(BaseHTTPRequestHandler):
    def send_json(self, data: dict, status: int = 200) -> None:
        body = json.dumps(data, ensure_ascii=False, indent=2).encode("utf-8")

        self.send_response(status)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def read_json_body(self) -> dict:
        length = int(self.headers.get("Content-Length", "0"))

        if length <= 0:
            return {}

        raw = self.rfile.read(length).decode("utf-8")
        return json.loads(raw)

    def do_GET(self) -> None:
        path = urlparse(self.path).path

        if path == "/health":
            self.send_json(health())
            return

        if path == "/products":
            self.send_json(list_products(DB_PATH))
            return

        if path == "/orders":
            self.send_json(list_orders(DB_PATH))
            return

        self.send_json({"ok": False, "error": "not found"}, status=404)

    def do_POST(self) -> None:
        path = urlparse(self.path).path

        try:
            payload = self.read_json_body()
        except json.JSONDecodeError:
            self.send_json({"ok": False, "error": "invalid json"}, status=400)
            return

        if path == "/products":
            result = add_product(DB_PATH, payload)
            self.send_json(result, status=result.get("status", 200))
            return

        if path == "/orders":
            result = add_order(DB_PATH, payload)
            self.send_json(result, status=result.get("status", 200))
            return

        self.send_json({"ok": False, "error": "not found"}, status=404)

    def log_message(self, format, *args) -> None:
        print(f"[API] {self.address_string()} - {format % args}")


def run_demo() -> int:
    print("=== RLX Local JSON API Demo ===")

    for result in demo_operations(DB_PATH):
        print_json(result)

    return 0


def run_server() -> int:
    server = HTTPServer((HOST, PORT), LocalApiHandler)

    print(f"RLX Local JSON API running on http://{HOST}:{PORT}")
    print("Routes:")
    print("  GET  /health")
    print("  GET  /products")
    print("  POST /products")
    print("  GET  /orders")
    print("  POST /orders")
    print("Stop: Ctrl + C")

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\nServer stopped.")

    server.server_close()
    return 0


def main() -> int:
    if len(sys.argv) > 1 and sys.argv[1] == "--demo":
        return run_demo()

    if len(sys.argv) > 1 and sys.argv[1] == "--serve":
        return run_server()

    print("Usage:")
    print("  python app.py --demo")
    print("  python app.py --serve")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
