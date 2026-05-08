import unittest
from pathlib import Path
from tempfile import TemporaryDirectory

from src.data_tools import (
    Sale,
    total_revenue,
    average_ticket,
    best_product,
    revenue_by_category,
    format_money,
    generate_bar_chart_svg,
)


class DataToolsTests(unittest.TestCase):
    def setUp(self):
        self.sales = [
            Sale("A", "Tech", 2, 100),
            Sale("B", "Tech", 3, 50),
            Sale("C", "Office", 1, 300),
        ]

    def test_total_revenue(self):
        self.assertEqual(total_revenue(self.sales), 650)

    def test_average_ticket(self):
        self.assertAlmostEqual(average_ticket(self.sales), 650 / 6)

    def test_best_product(self):
        self.assertEqual(best_product(self.sales).product, "C")

    def test_revenue_by_category(self):
        self.assertEqual(revenue_by_category(self.sales)["Tech"], 350)
        self.assertEqual(revenue_by_category(self.sales)["Office"], 300)

    def test_format_money(self):
        self.assertEqual(format_money(1250000), "1 250 000 FCFA")

    def test_generate_svg(self):
        with TemporaryDirectory() as tmp:
            path = Path(tmp) / "chart.svg"
            generate_bar_chart_svg({"A": 100, "B": 200}, path)
            self.assertTrue(path.exists())
            self.assertIn("<svg", path.read_text(encoding="utf-8"))


if __name__ == "__main__":
    unittest.main()
