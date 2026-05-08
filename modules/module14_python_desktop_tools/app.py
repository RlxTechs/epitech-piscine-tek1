import sys
import tkinter as tk
from tkinter import messagebox

from src.desktop_logic import (
    DesktopState,
    add_task,
    toggle_task,
    task_summary,
    calculate_total,
    format_money,
    demo_state,
)


class DesktopToolApp:
    def __init__(self) -> None:
        self.state = DesktopState()

        self.root = tk.Tk()
        self.root.title("RLX Python Desktop Tools")
        self.root.geometry("760x520")

        self.title_label = tk.Label(
            self.root,
            text="RLX Desktop Tools",
            font=("Arial", 24, "bold"),
        )
        self.title_label.pack(pady=12)

        self.task_entry = tk.Entry(self.root, font=("Arial", 14), width=42)
        self.task_entry.pack(pady=8)

        self.add_button = tk.Button(self.root, text="Ajouter tâche", command=self.add_task)
        self.add_button.pack()

        self.listbox = tk.Listbox(self.root, font=("Arial", 13), width=70, height=12)
        self.listbox.pack(pady=12)
        self.listbox.bind("<Double-Button-1>", self.toggle_selected)

        self.summary_label = tk.Label(self.root, text="0/0 done", font=("Arial", 13))
        self.summary_label.pack()

        self.calc_button = tk.Button(
            self.root,
            text="Demo calcul total",
            command=self.demo_calculation,
        )
        self.calc_button.pack(pady=12)

    def refresh(self) -> None:
        self.listbox.delete(0, tk.END)
        for task in self.state.tasks:
            prefix = "[x]" if task.done else "[ ]"
            self.listbox.insert(tk.END, f"{prefix} {task.title}")
        self.summary_label.config(text=task_summary(self.state))

    def add_task(self) -> None:
        try:
            add_task(self.state, self.task_entry.get())
            self.task_entry.delete(0, tk.END)
            self.refresh()
        except ValueError as error:
            messagebox.showerror("Erreur", str(error))

    def toggle_selected(self, _event=None) -> None:
        selected = self.listbox.curselection()
        if not selected:
            return
        toggle_task(self.state, selected[0])
        self.refresh()

    def demo_calculation(self) -> None:
        items = [
            ("Laptop", 2, 250000),
            ("Souris", 4, 5000),
            ("Clavier", 3, 10000),
        ]
        total = calculate_total(items)
        messagebox.showinfo("Total", format_money(total))

    def run(self) -> None:
        self.root.mainloop()


def run_headless() -> int:
    state = demo_state()
    total = calculate_total([("Laptop", 2, 250000), ("Souris", 4, 5000)])
    print("=== Python Desktop Tools Headless Demo ===")
    print(f"tasks={len(state.tasks)}")
    print(f"summary={task_summary(state)}")
    print(f"total={format_money(total)}")
    return 0


def main() -> int:
    if len(sys.argv) > 1 and sys.argv[1] == "--headless":
        return run_headless()

    app = DesktopToolApp()
    app.run()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
