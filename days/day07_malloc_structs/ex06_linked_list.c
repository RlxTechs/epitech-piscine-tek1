#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int value;
    struct node_s *next;
} node_t;

node_t *create_node(int value)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

int push_front(node_t **list, int value)
{
    node_t *node = create_node(value);

    if (node == NULL) {
        return 0;
    }
    node->next = *list;
    *list = node;
    return 1;
}

void print_list(node_t *list)
{
    node_t *current = list;

    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void free_list(node_t *list)
{
    node_t *current = list;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void)
{
    node_t *list = NULL;

    if (push_front(&list, 10) == 0) {
        return 1;
    }
    if (push_front(&list, 20) == 0) {
        free_list(list);
        return 1;
    }
    if (push_front(&list, 30) == 0) {
        free_list(list);
        return 1;
    }
    print_list(list);
    free_list(list);
    return 0;
}
