#include <stdio.h>
#include <dirent.h>

int is_dot_entry(char *name)
{
    if (name[0] == '.' && name[1] == '\0') {
        return 1;
    }
    if (name[0] == '.' && name[1] == '.' && name[2] == '\0') {
        return 1;
    }
    return 0;
}

int my_strcmp(char *a, char *b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
        i = i + 1;
    }
    return a[i] - b[i];
}

int should_show(char *name, int show_hidden)
{
    if (is_dot_entry(name) == 1) {
        return 0;
    }
    if (show_hidden == 0 && name[0] == '.') {
        return 0;
    }
    return 1;
}

int mini_ls(char *path, int show_hidden)
{
    DIR *dir = opendir(path);
    struct dirent *entry = NULL;

    if (dir == NULL) {
        printf("mini_ls: cannot open %s\n", path);
        return 0;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        if (should_show(entry->d_name, show_hidden) == 1) {
            printf("%s\n", entry->d_name);
        }
        entry = readdir(dir);
    }
    closedir(dir);
    return 1;
}

int main(int argc, char **argv)
{
    int show_hidden = 0;
    char *path = ".";

    if (argc == 2) {
        if (my_strcmp(argv[1], "-a") == 0) {
            show_hidden = 1;
        } else {
            path = argv[1];
        }
    } else if (argc == 3) {
        if (my_strcmp(argv[1], "-a") == 0) {
            show_hidden = 1;
            path = argv[2];
        } else {
            printf("Usage: %s [-a] [path]\n", argv[0]);
            return 1;
        }
    } else if (argc > 3) {
        printf("Usage: %s [-a] [path]\n", argv[0]);
        return 1;
    }
    if (mini_ls(path, show_hidden) == 0) {
        return 1;
    }
    return 0;
}
