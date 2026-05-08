#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
    char *path = join_path("inputs/sample_dir", "alpha.txt");

    if (path == NULL) {
        return 1;
    }
    printf("%s\n", path);
    free(path);
    return 0;
}
