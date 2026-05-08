import sys
from pathlib import Path

from src.ai_engine import demo, load_memory, generate_reply


ROOT = Path(__file__).resolve().parent
MEMORY_PATH = ROOT / "data" / "memory.json"


def run_demo() -> int:
    print("=== RLX AI Tools Python Demo ===")
    replies = demo(MEMORY_PATH)
    for index, reply in enumerate(replies, start=1):
        print(f"\n--- Reply {index} ---")
        print(reply)
    return 0


def main() -> int:
    if len(sys.argv) > 1 and sys.argv[1] == "--demo":
        return run_demo()

    if len(sys.argv) > 1:
        memory = load_memory(MEMORY_PATH)
        message = " ".join(sys.argv[1:])
        print(generate_reply(message, memory))
        return 0

    print("Usage:")
    print("  python app.py --demo")
    print('  python app.py "tv 32 dispo ?"')
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
