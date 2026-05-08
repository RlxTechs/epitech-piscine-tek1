from dataclasses import dataclass, field
import random

WIDTH = 800
HEIGHT = 500
PLAYER_SIZE = 42
COIN_SIZE = 24
PLAYER_SPEED = 18


@dataclass
class Rect:
    x: int
    y: int
    width: int
    height: int


@dataclass
class GameState:
    player_x: int
    player_y: int
    coin_x: int
    coin_y: int
    score: int = 0
    moves: int = 0
    collected: int = 0
    rng: random.Random = field(default_factory=random.Random, repr=False)


def clamp(value: int, minimum: int, maximum: int) -> int:
    if value < minimum:
        return minimum
    if value > maximum:
        return maximum
    return value


def rects_overlap(a: Rect, b: Rect) -> bool:
    if a.x + a.width < b.x:
        return False
    if b.x + b.width < a.x:
        return False
    if a.y + a.height < b.y:
        return False
    if b.y + b.height < a.y:
        return False
    return True


def player_rect(state: GameState) -> Rect:
    return Rect(state.player_x, state.player_y, PLAYER_SIZE, PLAYER_SIZE)


def coin_rect(state: GameState) -> Rect:
    return Rect(state.coin_x, state.coin_y, COIN_SIZE, COIN_SIZE)


def spawn_coin(state: GameState) -> None:
    state.coin_x = state.rng.randint(20, WIDTH - COIN_SIZE - 20)
    state.coin_y = state.rng.randint(20, HEIGHT - COIN_SIZE - 20)


def create_game(seed: int = 42) -> GameState:
    rng = random.Random(seed)
    state = GameState(
        player_x=WIDTH // 2 - PLAYER_SIZE // 2,
        player_y=HEIGHT // 2 - PLAYER_SIZE // 2,
        coin_x=0,
        coin_y=0,
        rng=rng,
    )
    spawn_coin(state)
    return state


def move_player(state: GameState, dx: int, dy: int) -> None:
    state.player_x = clamp(state.player_x + dx, 0, WIDTH - PLAYER_SIZE)
    state.player_y = clamp(state.player_y + dy, 0, HEIGHT - PLAYER_SIZE)
    state.moves += 1

    if rects_overlap(player_rect(state), coin_rect(state)):
        state.score += 10
        state.collected += 1
        spawn_coin(state)


def apply_input(state: GameState, key: str) -> None:
    key = key.lower()
    if key in ("left", "a"):
        move_player(state, -PLAYER_SPEED, 0)
    elif key in ("right", "d"):
        move_player(state, PLAYER_SPEED, 0)
    elif key in ("up", "w"):
        move_player(state, 0, -PLAYER_SPEED)
    elif key in ("down", "s"):
        move_player(state, 0, PLAYER_SPEED)


def simulate_script(script: str, seed: int = 42) -> GameState:
    state = create_game(seed)
    for key in script:
        apply_input(state, key)
    return state
