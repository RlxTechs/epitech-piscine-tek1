import sys

from src.arcade_logic import (
    WIDTH,
    HEIGHT,
    PLAYER_SIZE,
    COIN_SIZE,
    ENEMY_SIZE,
    create_game,
    step,
    simulate_script,
)


def run_headless() -> int:
    state = simulate_script("ddddssssaaaawwwwddddssss", seed=42)
    print("=== Pygame Arcade Headless Demo ===")
    print(f"player=({state.player.x},{state.player.y})")
    print(f"enemy=({state.enemy.x},{state.enemy.y})")
    print(f"coin=({state.coin.x},{state.coin.y})")
    print(f"score={state.score}")
    print(f"lives={state.lives}")
    print(f"moves={state.moves}")
    print(f"running={state.running}")
    return 0


def run_pygame() -> int:
    try:
        import pygame
    except ImportError:
        print("pygame n'est pas installe.")
        print("Installe-le avec : python -m pip install pygame")
        print("Tu peux quand meme tester : python app.py --headless")
        return 1

    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("RLX Pygame Arcade")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("Arial", 24)

    state = create_game(seed=42)

    while state.running:
        key_name = ""

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                state.running = False
            elif event.type == pygame.KEYDOWN:
                key_name = pygame.key.name(event.key)

        keys = pygame.key.get_pressed()

        if keys[pygame.K_LEFT] or keys[pygame.K_a]:
            key_name = "left"
        elif keys[pygame.K_RIGHT] or keys[pygame.K_d]:
            key_name = "right"
        elif keys[pygame.K_UP] or keys[pygame.K_w]:
            key_name = "up"
        elif keys[pygame.K_DOWN] or keys[pygame.K_s]:
            key_name = "down"

        step(state, key_name)

        screen.fill((15, 23, 42))

        pygame.draw.rect(
            screen,
            (34, 197, 94),
            (state.player.x, state.player.y, PLAYER_SIZE, PLAYER_SIZE),
        )

        pygame.draw.rect(
            screen,
            (239, 68, 68),
            (state.enemy.x, state.enemy.y, ENEMY_SIZE, ENEMY_SIZE),
        )

        pygame.draw.ellipse(
            screen,
            (250, 204, 21),
            (state.coin.x, state.coin.y, COIN_SIZE, COIN_SIZE),
        )

        label = font.render(
            f"Score: {state.score} | Lives: {state.lives} | Moves: {state.moves}",
            True,
            (255, 255, 255),
        )
        screen.blit(label, (20, 20))

        pygame.display.flip()
        clock.tick(30)

    pygame.quit()
    return 0


def main() -> int:
    if len(sys.argv) > 1 and sys.argv[1] == "--headless":
        return run_headless()

    return run_pygame()


if __name__ == "__main__":
    raise SystemExit(main())
