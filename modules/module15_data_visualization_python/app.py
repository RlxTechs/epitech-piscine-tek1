from pathlib import Path

from src.data_tools import (
    read_sales,
    revenue_by_category,
    generate_report,
    generate_bar_chart_svg,
)


def main() -> int:
    root = Path(__file__).resolve().parent
    data_path = root / "data" / "sales.csv"
    output_dir = root / "output"
    output_dir.mkdir(exist_ok=True)

    sales = read_sales(data_path)

    report = generate_report(sales)
    report_path = output_dir / "report.txt"
    chart_path = output_dir / "revenue_by_category.svg"

    report_path.write_text(report, encoding="utf-8")
    generate_bar_chart_svg(revenue_by_category(sales), chart_path)

    print(report)
    print(f"Report saved: {report_path}")
    print(f"Chart saved: {chart_path}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
