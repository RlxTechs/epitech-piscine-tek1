import json
from pathlib import Path
from copy import deepcopy


DEFAULT_DB = {
    "products": [],
    "orders": [],
}


def load_db(path: str | Path) -> dict:
    path = Path(path)

    if not path.exists():
        save_db(path, deepcopy(DEFAULT_DB))

    with open(path, "r", encoding="utf-8-sig") as file:
        data = json.load(file)

    if "products" not in data:
        data["products"] = []

    if "orders" not in data:
        data["orders"] = []

    return data


def save_db(path: str | Path, data: dict) -> None:
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)

    with open(path, "w", encoding="utf-8") as file:
        json.dump(data, file, ensure_ascii=False, indent=2)


def next_id(items: list[dict]) -> int:
    if not items:
        return 1

    return max(int(item.get("id", 0)) for item in items) + 1


def reset_db(path: str | Path) -> dict:
    data = deepcopy(DEFAULT_DB)
    save_db(path, data)
    return data
