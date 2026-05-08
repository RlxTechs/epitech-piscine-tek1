from pathlib import Path

from src.json_db import load_db, save_db, next_id


def ok(data=None) -> dict:
    return {
        "ok": True,
        "data": data,
    }


def error(message: str, status: int = 400) -> dict:
    return {
        "ok": False,
        "status": status,
        "error": message,
    }


def list_products(db_path: str | Path) -> dict:
    data = load_db(db_path)
    return ok(data["products"])


def add_product(db_path: str | Path, payload: dict) -> dict:
    required = ["name", "category", "price", "stock"]

    for key in required:
        if key not in payload:
            return error(f"missing field: {key}")

    if int(payload["price"]) < 0 or int(payload["stock"]) < 0:
        return error("price and stock must be positive")

    data = load_db(db_path)

    product = {
        "id": next_id(data["products"]),
        "name": str(payload["name"]).strip(),
        "category": str(payload["category"]).strip(),
        "price": int(payload["price"]),
        "stock": int(payload["stock"]),
    }

    if not product["name"]:
        return error("product name cannot be empty")

    data["products"].append(product)
    save_db(db_path, data)

    return ok(product)


def list_orders(db_path: str | Path) -> dict:
    data = load_db(db_path)
    return ok(data["orders"])


def add_order(db_path: str | Path, payload: dict) -> dict:
    required = ["customer", "product_id", "quantity"]

    for key in required:
        if key not in payload:
            return error(f"missing field: {key}")

    quantity = int(payload["quantity"])

    if quantity <= 0:
        return error("quantity must be greater than zero")

    data = load_db(db_path)

    product_id = int(payload["product_id"])
    product = None

    for item in data["products"]:
        if int(item["id"]) == product_id:
            product = item
            break

    if product is None:
        return error("product not found", status=404)

    if int(product["stock"]) < quantity:
        return error("not enough stock")

    product["stock"] = int(product["stock"]) - quantity

    order = {
        "id": next_id(data["orders"]),
        "customer": str(payload["customer"]).strip(),
        "product_id": product_id,
        "product_name": product["name"],
        "quantity": quantity,
        "unit_price": int(product["price"]),
        "total": int(product["price"]) * quantity,
    }

    if not order["customer"]:
        return error("customer cannot be empty")

    data["orders"].append(order)
    save_db(db_path, data)

    return ok(order)


def health() -> dict:
    return ok({
        "service": "RLX Local JSON API",
        "status": "running",
    })


def demo_operations(db_path: str | Path) -> list[dict]:
    results = []

    results.append(health())
    results.append(list_products(db_path))

    results.append(add_product(db_path, {
        "name": "Stabilisateur 2000VA",
        "category": "Electronics",
        "price": 35000,
        "stock": 10,
    }))

    results.append(add_order(db_path, {
        "customer": "Client Demo",
        "product_id": 1,
        "quantity": 1,
    }))

    results.append(list_orders(db_path))

    return results
