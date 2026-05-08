import unittest
from pathlib import Path
from tempfile import TemporaryDirectory

from src.json_db import reset_db, load_db, save_db
from src.api_logic import (
    health,
    list_products,
    add_product,
    list_orders,
    add_order,
)


class LocalJsonApiTests(unittest.TestCase):
    def setUp(self):
        self.tmp = TemporaryDirectory()
        self.db_path = Path(self.tmp.name) / "db.json"
        reset_db(self.db_path)

    def tearDown(self):
        self.tmp.cleanup()

    def test_health(self):
        result = health()
        self.assertTrue(result["ok"])
        self.assertEqual(result["data"]["status"], "running")

    def test_add_product(self):
        result = add_product(self.db_path, {
            "name": "Laptop",
            "category": "Tech",
            "price": 250000,
            "stock": 5,
        })

        self.assertTrue(result["ok"])
        self.assertEqual(result["data"]["id"], 1)

        products = list_products(self.db_path)["data"]
        self.assertEqual(len(products), 1)

    def test_add_product_reject_missing(self):
        result = add_product(self.db_path, {
            "name": "Laptop",
        })

        self.assertFalse(result["ok"])
        self.assertIn("missing field", result["error"])

    def test_add_order(self):
        add_product(self.db_path, {
            "name": "TV",
            "category": "Electronics",
            "price": 120000,
            "stock": 3,
        })

        result = add_order(self.db_path, {
            "customer": "Client A",
            "product_id": 1,
            "quantity": 2,
        })

        self.assertTrue(result["ok"])
        self.assertEqual(result["data"]["total"], 240000)

        data = load_db(self.db_path)
        self.assertEqual(data["products"][0]["stock"], 1)

    def test_add_order_reject_stock(self):
        add_product(self.db_path, {
            "name": "TV",
            "category": "Electronics",
            "price": 120000,
            "stock": 1,
        })

        result = add_order(self.db_path, {
            "customer": "Client A",
            "product_id": 1,
            "quantity": 2,
        })

        self.assertFalse(result["ok"])
        self.assertEqual(result["error"], "not enough stock")

    def test_list_orders(self):
        self.assertEqual(list_orders(self.db_path)["data"], [])


if __name__ == "__main__":
    unittest.main()
