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

int is_hidden(char *name)
{
    return name[0] == '.';
}

int count_visible_entries(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry = NULL;
    int count = 0;

    if (dir == NULL) {
        return -1;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        if (is_dot_entry(entry->d_name) == 0 && is_hidden(entry->d_name) == 0) {
            count = count + 1;
        }
        entry = readdir(dir);
    }
    closedir(dir);
    return count;
}

int main(int argc, char **argv)
{
    int count = 0;

    if (argc != 2) {
        printf("Usage: %s path\n", argv[0]);
        return 1;
    }
    count = count_visible_entries(argv[1]);
    if (count < 0) {
        printf("Cannot open directory\n");
        return 1;
    }
    printf("visible entries = %d\n", count);
    return 0;
}
