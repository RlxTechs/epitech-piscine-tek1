import sys
import tkinter as tk

from src.game_logic import (
    WIDTH,
    HEIGHT,
    PLAYER_SIZE,
    COIN_SIZE,
    create_game,
    apply_input,
    simulate_script,
)


class TkinterGameApp:
    def __init__(self) -> None:
        self.root = tk.Tk()
        self.root.title("RLX Python Graphics - Coin Collector")
        self.root.resizable(False, False)

        self.state = create_game(seed=42)

        self.canvas = tk.Canvas(self.root, width=WIDTH, height=HEIGHT, bg="#111827")
        self.canvas.pack()

        self.root.bind("<KeyPress>", self.on_key_press)
        self.draw()

    def on_key_press(self, event) -> None:
        apply_input(self.state, event.keysym)
        self.draw()

    def draw(self) -> None:
        self.canvas.delete("all")

        self.canvas.create_rectangle(0, 0, WIDTH, HEIGHT, fill="#111827", outline="")

        self.canvas.create_text(
            20,
            20,
            anchor="w",
            text=f"Score: {self.state.score} | Moves: {self.state.moves} | Coins: {self.state.collected}",
            fill="white",
            font=("Arial", 16, "bold"),
        )

        self.canvas.create_oval(
            self.state.coin_x,
            self.state.coin_y,
            self.state.coin_x + COIN_SIZE,
            self.state.coin_y + COIN_SIZE,
            fill="#facc15",
            outline="#fde68a",
            width=3,
        )

        self.canvas.create_rectangle(
            self.state.player_x,
            self.state.player_y,
            self.state.player_x + PLAYER_SIZE,
            self.state.player_y + PLAYER_SIZE,
            fill="#22c55e",
            outline="#bbf7d0",
            width=3,
        )

        self.canvas.create_text(
            WIDTH // 2,
            HEIGHT - 24,
            text="Move with arrows or WASD",
            fill="#9ca3af",
            font=("Arial", 12),
        )

    def run(self) -> None:
        self.root.mainloop()


def run_headless_demo() -> int:
    state = simulate_script("ddddssssaaaawwwddss", seed=42)
    print("=== Headless Tkinter Game Demo ===")
    print(f"player=({state.player_x},{state.player_y})")
    print(f"coin=({state.coin_x},{state.coin_y})")
    print(f"score={state.score}")
    print(f"moves={state.moves}")
    print(f"collected={state.collected}")
    return 0


def main() -> int:
    if len(sys.argv) > 1 and sys.argv[1] == "--headless":
        return run_headless_demo()

    app = TkinterGameApp()
    app.run()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
