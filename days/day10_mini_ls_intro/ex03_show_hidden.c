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

int list_all_entries(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry = NULL;

    if (dir == NULL) {
        return 0;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        if (is_dot_entry(entry->d_name) == 0) {
            printf("%s\n", entry->d_name);
        }
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
    if (list_all_entries(argv[1]) == 0) {
        printf("Cannot open directory\n");
        return 1;
    }
    return 0;
}
