from dataclasses import dataclass, field
from datetime import datetime


@dataclass
class Task:
    title: str
    done: bool = False


@dataclass
class DesktopState:
    tasks: list[Task] = field(default_factory=list)
    notes: list[str] = field(default_factory=list)


def calculate_total(items: list[tuple[str, int, int]]) -> int:
    total = 0
    for _name, qty, price in items:
        if qty < 0 or price < 0:
            raise ValueError("qty and price must be positive")
        total += qty * price
    return total


def format_money(value: int) -> str:
    return f"{value:,} FCFA".replace(",", " ")


def add_task(state: DesktopState, title: str) -> None:
    title = title.strip()
    if not title:
        raise ValueError("task title cannot be empty")
    state.tasks.append(Task(title=title))


def toggle_task(state: DesktopState, index: int) -> None:
    if index < 0 or index >= len(state.tasks):
        raise IndexError("invalid task index")
    state.tasks[index].done = not state.tasks[index].done


def task_summary(state: DesktopState) -> str:
    done = sum(1 for task in state.tasks if task.done)
    return f"{done}/{len(state.tasks)} done"


def create_note(title: str, body: str) -> str:
    now = datetime.now().strftime("%Y-%m-%d %H:%M")
    title = title.strip() or "Untitled"
    body = body.strip()
    return f"# {title}\n\nCreated: {now}\n\n{body}\n"


def demo_state() -> DesktopState:
    state = DesktopState()
    add_task(state, "Reviser C")
    add_task(state, "Tester les modules")
    add_task(state, "Pousser sur GitHub")
    toggle_task(state, 0)
    state.notes.append(create_note("RLX Desktop Tool", "Premiere note generee."))
    return state
