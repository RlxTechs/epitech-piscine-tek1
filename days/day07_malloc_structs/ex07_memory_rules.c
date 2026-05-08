#include <stdio.h>

int main(void)
{
    printf("Memory rules in C:\n");
    printf("1. Every malloc must be checked.\n");
    printf("2. Every malloc must have a free.\n");
    printf("3. Do not use memory after free.\n");
    printf("4. Do not free the same pointer twice.\n");
    printf("5. Set complex structures free from inside to outside.\n");
    return 0;
}
