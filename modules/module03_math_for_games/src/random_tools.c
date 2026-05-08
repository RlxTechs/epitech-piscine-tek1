#include <stdlib.h>
#include "math_game.h"

void rng_seed(unsigned int seed)
{
    srand(seed);
}

int random_int(int min, int max)
{
    int temp = 0;
    int range = 0;

    if (min > max) {
        temp = min;
        min = max;
        max = temp;
    }
    range = max - min + 1;
    return min + rand() % range;
}

double random_double(double min, double max)
{
    double temp = 0.0;
    double ratio = 0.0;

    if (min > max) {
        temp = min;
        min = max;
        max = temp;
    }
    ratio = (double)rand() / (double)RAND_MAX;
    return min + ratio * (max - min);
}
