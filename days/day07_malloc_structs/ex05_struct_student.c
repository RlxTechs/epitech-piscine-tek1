#include <stdio.h>
#include <stdlib.h>

typedef struct student_s {
    char *name;
    int age;
    int level;
} student_t;

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

char *my_strdup(char *src)
{
    int len = my_strlen(src);
    char *copy = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (copy == NULL) {
        return NULL;
    }
    while (src[i] != '\0') {
        copy[i] = src[i];
        i = i + 1;
    }
    copy[i] = '\0';
    return copy;
}

student_t *create_student(char *name, int age, int level)
{
    student_t *student = malloc(sizeof(student_t));

    if (student == NULL) {
        return NULL;
    }
    student->name = my_strdup(name);
    if (student->name == NULL) {
        free(student);
        return NULL;
    }
    student->age = age;
    student->level = level;
    return student;
}

void destroy_student(student_t *student)
{
    if (student == NULL) {
        return;
    }
    free(student->name);
    free(student);
}

int main(void)
{
    student_t *student = create_student("RLX", 23, 1);

    if (student == NULL) {
        return 1;
    }
    printf("name=%s age=%d level=%d\n", student->name, student->age, student->level);
    destroy_student(student);
    return 0;
}
