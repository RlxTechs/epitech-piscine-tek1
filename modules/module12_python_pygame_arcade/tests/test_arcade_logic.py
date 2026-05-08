import unittest

from src.arcade_logic import (
    WIDTH,
    HEIGHT,
    PLAYER_SIZE,
    Rect,
    clamp,
    rects_overlap,
    create_game,
    move_player,
    update_enemy,
    simulate_script,
)


class ArcadeLogicTests(unittest.TestCase):
    def test_clamp(self):
        self.assertEqual(clamp(-5, 0, 10), 0)
        self.assertEqual(clamp(15, 0, 10), 10)
        self.assertEqual(clamp(5, 0, 10), 5)

    def test_rects_overlap(self):
        self.assertTrue(rects_overlap(Rect(0, 0, 10, 10), Rect(5, 5, 10, 10)))
        self.assertFalse(rects_overlap(Rect(0, 0, 10, 10), Rect(50, 50, 10, 10)))

    def test_create_game(self):
        state = create_game(seed=42)
        self.assertEqual(state.score, 0)
        self.assertEqual(state.lives, 3)
        self.assertTrue(state.running)

    def test_move_bounds(self):
        state = create_game(seed=42)
        move_player(state, -9999, -9999)
        self.assertEqual(state.player.x, 0)
        self.assertEqual(state.player.y, 0)
        move_player(state, 9999, 9999)
        self.assertEqual(state.player.x, WIDTH - PLAYER_SIZE)
        self.assertEqual(state.player.y, HEIGHT - PLAYER_SIZE)

    def test_collect_coin(self):
        state = create_game(seed=42)
        state.coin.x = state.player.x
        state.coin.y = state.player.y
        move_player(state, 0, 0)
        self.assertEqual(state.score, 10)

    def test_enemy_collision(self):
        state = create_game(seed=42)
        state.enemy.x = state.player.x
        state.enemy.y = state.player.y
        update_enemy(state)
        self.assertEqual(state.lives, 2)

    def test_script(self):
        state = simulate_script("ddssaaww", seed=42)
        self.assertEqual(state.moves, 8)


if __name__ == "__main__":
    unittest.main()
