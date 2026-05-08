#include <stdio.h>
#include "level_loader.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s level_file\\n", argv[0]);
        printf("Example: %s levels/level_valid.txt\\n", argv[0]);
        return 1;
    }
    return level_demo(argv[1]);
}
