#include "game_runner.h"

static game_module_t modules[MODULE_COUNT] = {
    {
        1,
        "Terminal Game Engine",
        "Mini moteur de jeu terminal avec joueur, ennemi, piece et collisions.",
        "../module04_terminal_game_engine/terminal_game.exe --script"
    },
    {
        2,
        "Grid Game",
        "Jeu sur grille avec pieces, sortie, murs et pathfinding.",
        "../module05_grid_games/grid_game.exe --demo"
    },
    {
        3,
        "Snake Terminal",
        "Mini Snake terminal avec croissance, nourriture, score et collisions.",
        "../module06_snake_terminal/snake_game.exe --demo"
    },
    {
        4,
        "AI Game Logic",
        "Demos IA : poursuite, fuite, patrouille et mouvement aleatoire.",
        "../module07_ai_game_logic/ai_game_demo.exe"
    },
    {
        5,
        "Collision Physics",
        "Base physique 2D : vitesse, gravite, collisions et rebonds.",
        "../module08_collision_physics/physics_demo.exe"
    }
};

int runner_count_modules(void)
{
    return MODULE_COUNT;
}

game_module_t runner_get_module(int index)
{
    game_module_t empty;

    empty.id = 0;
    empty.name = "Invalid";
    empty.description = "Invalid module";
    empty.command = "";
    if (index < 0 || index >= MODULE_COUNT) {
        return empty;
    }
    return modules[index];
}
