import csv
from dataclasses import dataclass
from pathlib import Path


@dataclass
class Sale:
    product: str
    category: str
    quantity: int
    price: int

    @property
    def total(self) -> int:
        return self.quantity * self.price


def clean_key(key: str) -> str:
    return key.replace("\ufeff", "").strip()


def clean_row(row: dict) -> dict:
    return {clean_key(key): value for key, value in row.items()}


def read_sales(path: str | Path) -> list[Sale]:
    rows: list[Sale] = []

    with open(path, newline="", encoding="utf-8-sig") as file:
        reader = csv.DictReader(file)

        for raw_row in reader:
            row = clean_row(raw_row)
            rows.append(
                Sale(
                    product=row["product"],
                    category=row["category"],
                    quantity=int(row["quantity"]),
                    price=int(row["price"]),
                )
            )

    return rows


def total_revenue(sales: list[Sale]) -> int:
    return sum(sale.total for sale in sales)


def average_ticket(sales: list[Sale]) -> float:
    if not sales:
        return 0.0

    total_quantity = sum(sale.quantity for sale in sales)

    if total_quantity == 0:
        return 0.0

    return total_revenue(sales) / total_quantity


def best_product(sales: list[Sale]) -> Sale | None:
    if not sales:
        return None

    return max(sales, key=lambda sale: sale.total)


def revenue_by_category(sales: list[Sale]) -> dict[str, int]:
    result: dict[str, int] = {}

    for sale in sales:
        result[sale.category] = result.get(sale.category, 0) + sale.total

    return result


def format_money(value: float) -> str:
    return f"{int(round(value)):,} FCFA".replace(",", " ")


def generate_report(sales: list[Sale]) -> str:
    best = best_product(sales)

    lines = [
        "=== RLX Data Report ===",
        f"Products: {len(sales)}",
        f"Total revenue: {format_money(total_revenue(sales))}",
        f"Average ticket: {format_money(average_ticket(sales))}",
    ]

    if best:
        lines.append(f"Best product: {best.product} ({format_money(best.total)})")

    lines.append("")
    lines.append("Revenue by category:")

    for category, total in sorted(revenue_by_category(sales).items()):
        lines.append(f"- {category}: {format_money(total)}")

    return "\n".join(lines) + "\n"


def generate_bar_chart_svg(values: dict[str, int], output_path: str | Path) -> None:
    width = 900
    height = 420
    margin = 60
    max_value = max(values.values()) if values else 1
    bar_count = max(len(values), 1)
    bar_width = (width - margin * 2) / bar_count * 0.7
    gap = (width - margin * 2) / bar_count * 0.3

    parts = [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}">',
        '<rect width="100%" height="100%" fill="#0f172a"/>',
        '<text x="40" y="38" fill="white" font-size="24" font-family="Arial" font-weight="bold">RLX Revenue by Category</text>',
    ]

    x = margin

    for label, value in sorted(values.items()):
        bar_height = (value / max_value) * (height - 150)
        y = height - margin - bar_height

        parts.append(
            f'<rect x="{x:.1f}" y="{y:.1f}" width="{bar_width:.1f}" height="{bar_height:.1f}" fill="#22c55e" rx="8"/>'
        )
        parts.append(
            f'<text x="{x:.1f}" y="{height - 30}" fill="white" font-size="14" font-family="Arial">{label}</text>'
        )
        parts.append(
            f'<text x="{x:.1f}" y="{y - 8:.1f}" fill="#d1fae5" font-size="13" font-family="Arial">{format_money(value)}</text>'
        )

        x += bar_width + gap

    parts.append("</svg>")

    Path(output_path).write_text("\n".join(parts), encoding="utf-8")
