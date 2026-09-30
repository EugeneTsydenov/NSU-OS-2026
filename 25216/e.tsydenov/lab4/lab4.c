#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

typedef struct Node {
    char *value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} List;

void list_init(List *list) {
    list->head = NULL;
    list->size = 0;
}

void list_push(List *list, const char *str) {
    Node *n = malloc(sizeof(Node));
    n->value = malloc(strlen(str) + 1);
    strcpy(n->value, str);
    n->next = NULL;

    if (list->head == NULL) {
        list->head = n;
    } else {
        Node *last = list->head;
        while (last->next)
            last = last->next;
        last->next = n;
    }
    list->size++;
}

void list_print(const List *list) {
    Node *n;
    for (n = list->head; n; n = n->next)
        puts(n->value);
}

void list_clear(List *list) {
    Node *n = list->head;
    while (n) {
        Node *next = n->next;
        free(n->value);
        free(n);
        n = next;
    }
    list->head = NULL;
    list->size = 0;
}

int main(void) {
    List list;
    list_init(&list);

    char line[BUF_SIZE];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '.')
            break;

        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        list_push(&list, line);
    }

    list_print(&list);
    list_clear(&list);

    return 0;
}