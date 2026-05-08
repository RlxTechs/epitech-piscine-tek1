import unittest

from src.game_logic import (
    WIDTH,
    HEIGHT,
    PLAYER_SIZE,
    COIN_SIZE,
    Rect,
    clamp,
    rects_overlap,
    create_game,
    move_player,
    simulate_script,
)


class GameLogicTests(unittest.TestCase):
    def test_clamp(self):
        self.assertEqual(clamp(-5, 0, 10), 0)
        self.assertEqual(clamp(15, 0, 10), 10)
        self.assertEqual(clamp(5, 0, 10), 5)

    def test_rects_overlap(self):
        a = Rect(0, 0, 10, 10)
        b = Rect(5, 5, 10, 10)
        c = Rect(30, 30, 5, 5)
        self.assertTrue(rects_overlap(a, b))
        self.assertFalse(rects_overlap(a, c))

    def test_create_game_bounds(self):
        state = create_game(seed=42)
        self.assertGreaterEqual(state.coin_x, 20)
        self.assertGreaterEqual(state.coin_y, 20)
        self.assertLessEqual(state.coin_x, WIDTH - COIN_SIZE - 20)
        self.assertLessEqual(state.coin_y, HEIGHT - COIN_SIZE - 20)

    def test_move_player(self):
        state = create_game(seed=42)
        old_x = state.player_x
        move_player(state, 18, 0)
        self.assertEqual(state.player_x, old_x + 18)
        self.assertEqual(state.moves, 1)

    def test_bounds(self):
        state = create_game(seed=42)
        move_player(state, -9999, -9999)
        self.assertEqual(state.player_x, 0)
        self.assertEqual(state.player_y, 0)
        move_player(state, 9999, 9999)
        self.assertEqual(state.player_x, WIDTH - PLAYER_SIZE)
        self.assertEqual(state.player_y, HEIGHT - PLAYER_SIZE)

    def test_collect_coin(self):
        state = create_game(seed=42)
        state.coin_x = state.player_x
        state.coin_y = state.player_y
        move_player(state, 0, 0)
        self.assertEqual(state.score, 10)
        self.assertEqual(state.collected, 1)

    def test_simulate_script(self):
        state = simulate_script("ddssaaww", seed=42)
        self.assertEqual(state.moves, 8)


if __name__ == "__main__":
    unittest.main()
