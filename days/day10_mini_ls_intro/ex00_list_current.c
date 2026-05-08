#include <stdio.h>
#include <dirent.h>

int main(void)
{
    DIR *dir = opendir(".");
    struct dirent *entry = NULL;

    if (dir == NULL) {
        printf("Cannot open current directory\n");
        return 1;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        printf("%s\n", entry->d_name);
        entry = readdir(dir);
    }
    closedir(dir);
    return 0;
}
