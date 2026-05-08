#include <stdio.h>
#include "level_loader.h"

static int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

static void trim_newline(char *line)
{
    int len = my_strlen(line);

    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
        len = len - 1;
    }
    if (len > 0 && line[len - 1] == '\r') {
        line[len - 1] = '\0';
    }
}

static int copy_line(level_t *level, int y, char *line)
{
    int x = 0;

    while (line[x] != '\0') {
        if (x >= LEVEL_MAX_WIDTH) {
            return 0;
        }
        level->tiles[y][x] = line[x];
        x = x + 1;
    }
    level->tiles[y][x] = '\0';
    return x;
}

int level_load(level_t *level, const char *path)
{
    FILE *file = NULL;
    char line[LEVEL_MAX_WIDTH + 8];
    int line_width = 0;
    int current_width = 0;

    if (level == 0 || path == 0) {
        return 0;
    }
    level_clear(level);
    file = fopen(path, "r");
    if (file == NULL) {
        return 0;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        if (level->height >= LEVEL_MAX_HEIGHT) {
            fclose(file);
            return 0;
        }
        trim_newline(line);
        current_width = copy_line(level, level->height, line);
        if (current_width <= 0) {
            fclose(file);
            return 0;
        }
        if (line_width == 0) {
            line_width = current_width;
        } else if (line_width != current_width) {
            fclose(file);
            return 0;
        }
        level->height = level->height + 1;
    }
    fclose(file);
    level->width = line_width;
    return level->height > 0;
}
