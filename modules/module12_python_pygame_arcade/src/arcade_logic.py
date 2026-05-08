from dataclasses import dataclass, field
import random

WIDTH = 900
HEIGHT = 540
PLAYER_SIZE = 34
COIN_SIZE = 18
ENEMY_SIZE = 30
PLAYER_SPEED = 18


@dataclass
class Rect:
    x: int
    y: int
    width: int
    height: int


@dataclass
class Player:
    x: int
    y: int
    size: int = PLAYER_SIZE


@dataclass
class Enemy:
    x: int
    y: int
    dx: int
    dy: int
    size: int = ENEMY_SIZE


@dataclass
class Coin:
    x: int
    y: int
    size: int = COIN_SIZE


@dataclass
class ArcadeState:
    player: Player
    enemy: Enemy
    coin: Coin
    score: int = 0
    lives: int = 3
    moves: int = 0
    running: bool = True
    rng: random.Random = field(default_factory=random.Random, repr=False)


def clamp(value: int, minimum: int, maximum: int) -> int:
    return max(minimum, min(maximum, value))


def rects_overlap(a: Rect, b: Rect) -> bool:
    return not (
        a.x + a.width < b.x
        or b.x + b.width < a.x
        or a.y + a.height < b.y
        or b.y + b.height < a.y
    )


def player_rect(state: ArcadeState) -> Rect:
    return Rect(state.player.x, state.player.y, state.player.size, state.player.size)


def enemy_rect(state: ArcadeState) -> Rect:
    return Rect(state.enemy.x, state.enemy.y, state.enemy.size, state.enemy.size)


def coin_rect(state: ArcadeState) -> Rect:
    return Rect(state.coin.x, state.coin.y, state.coin.size, state.coin.size)


def spawn_coin(state: ArcadeState) -> None:
    state.coin.x = state.rng.randint(40, WIDTH - COIN_SIZE - 40)
    state.coin.y = state.rng.randint(60, HEIGHT - COIN_SIZE - 40)


def create_game(seed: int = 42) -> ArcadeState:
    rng = random.Random(seed)
    state = ArcadeState(
        player=Player(WIDTH // 2, HEIGHT // 2),
        enemy=Enemy(80, 80, 8, 6),
        coin=Coin(0, 0),
        rng=rng,
    )
    spawn_coin(state)
    return state


def move_player(state: ArcadeState, dx: int, dy: int) -> None:
    if not state.running:
        return

    state.player.x = clamp(state.player.x + dx, 0, WIDTH - state.player.size)
    state.player.y = clamp(state.player.y + dy, 0, HEIGHT - state.player.size)
    state.moves += 1

    if rects_overlap(player_rect(state), coin_rect(state)):
        state.score += 10
        spawn_coin(state)


def update_enemy(state: ArcadeState) -> None:
    if not state.running:
        return

    enemy = state.enemy
    enemy.x += enemy.dx
    enemy.y += enemy.dy

    if enemy.x < 0 or enemy.x + enemy.size > WIDTH:
        enemy.dx *= -1
        enemy.x = clamp(enemy.x, 0, WIDTH - enemy.size)

    if enemy.y < 0 or enemy.y + enemy.size > HEIGHT:
        enemy.dy *= -1
        enemy.y = clamp(enemy.y, 0, HEIGHT - enemy.size)

    if rects_overlap(player_rect(state), enemy_rect(state)):
        state.lives -= 1
        state.player.x = WIDTH // 2
        state.player.y = HEIGHT // 2

        if state.lives <= 0:
            state.running = False


def apply_input(state: ArcadeState, key: str) -> None:
    key = key.lower()

    if key in ("left", "a"):
        move_player(state, -PLAYER_SPEED, 0)
    elif key in ("right", "d"):
        move_player(state, PLAYER_SPEED, 0)
    elif key in ("up", "w"):
        move_player(state, 0, -PLAYER_SPEED)
    elif key in ("down", "s"):
        move_player(state, 0, PLAYER_SPEED)
    elif key in ("q", "escape"):
        state.running = False


def step(state: ArcadeState, key: str = "") -> None:
    apply_input(state, key)
    update_enemy(state)


def simulate_script(script: str, seed: int = 42) -> ArcadeState:
    state = create_game(seed)
    for key in script:
        step(state, key)
    return state
