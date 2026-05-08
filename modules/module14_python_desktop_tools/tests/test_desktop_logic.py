import unittest

from src.desktop_logic import (
    DesktopState,
    add_task,
    toggle_task,
    task_summary,
    calculate_total,
    format_money,
    create_note,
)


class DesktopLogicTests(unittest.TestCase):
    def test_calculate_total(self):
        items = [("A", 2, 100), ("B", 3, 50)]
        self.assertEqual(calculate_total(items), 350)

    def test_negative_total_rejected(self):
        with self.assertRaises(ValueError):
            calculate_total([("A", -1, 100)])

    def test_format_money(self):
        self.assertEqual(format_money(1250000), "1 250 000 FCFA")

    def test_tasks(self):
        state = DesktopState()
        add_task(state, "Coder")
        self.assertEqual(len(state.tasks), 1)
        self.assertEqual(task_summary(state), "0/1 done")
        toggle_task(state, 0)
        self.assertEqual(task_summary(state), "1/1 done")

    def test_empty_task_rejected(self):
        state = DesktopState()
        with self.assertRaises(ValueError):
            add_task(state, "   ")

    def test_create_note(self):
        note = create_note("Test", "Hello")
        self.assertIn("# Test", note)
        self.assertIn("Hello", note)


if __name__ == "__main__":
    unittest.main()
