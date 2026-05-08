#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

char *join_path(char *dir, char *name)
{
    int len_dir = my_strlen(dir);
    int len_name = my_strlen(name);
    int need_slash = 1;
    char *path = NULL;
    int i = 0;
    int j = 0;

    if (len_dir > 0 && (dir[len_dir - 1] == '/' || dir[len_dir - 1] == '\\')) {
        need_slash = 0;
    }
    path = malloc(sizeof(char) * (len_dir + len_name + need_slash + 1));
    if (path == NULL) {
        return NULL;
    }
    while (dir[i] != '\0') {
        path[i] = dir[i];
        i = i + 1;
    }
    if (need_slash == 1) {
        path[i] = '/';
        i = i + 1;
    }
    while (name[j] != '\0') {
        path[i + j] = name[j];
        j = j + 1;
    }
    path[i + j] = '\0';
    return path;
}

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

int is_directory(char *path)
{
    struct stat info;

    if (stat(path, &info) != 0) {
        return 0;
    }
    return S_ISDIR(info.st_mode);
}

void recursive_list(char *path, int depth)
{
    DIR *dir = opendir(path);
    struct dirent *entry = NULL;
    char *full_path = NULL;
    int i = 0;

    if (dir == NULL) {
        return;
    }
    printf("%s:\n", path);
    entry = readdir(dir);
    while (entry != NULL) {
        if (is_dot_entry(entry->d_name) == 0 && entry->d_name[0] != '.') {
            i = 0;
            while (i < depth) {
                printf("  ");
                i = i + 1;
            }
            printf("%s\n", entry->d_name);
            full_path = join_path(path, entry->d_name);
            if (full_path != NULL) {
                if (is_directory(full_path) == 1) {
                    recursive_list(full_path, depth + 1);
                }
                free(full_path);
            }
        }
        entry = readdir(dir);
    }
    closedir(dir);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s path\n", argv[0]);
        return 1;
    }
    recursive_list(argv[1], 0);
    return 0;
}
