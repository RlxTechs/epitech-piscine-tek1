#include <stdio.h>
#include <dirent.h>

int list_path(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry = NULL;

    if (dir == NULL) {
        printf("Cannot open directory: %s\n", path);
        return 0;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        printf("%s\n", entry->d_name);
        entry = readdir(dir);
    }
    closedir(dir);
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s path\n", argv[0]);
        return 1;
    }
    if (list_path(argv[1]) == 0) {
        return 1;
    }
    return 0;
}
