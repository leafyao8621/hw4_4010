#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

struct Node {
    Node* next;
    Node* previous;
    void* data;
}

Node* new_Node(void* data) {
    Node* opt = malloc(sizeof(Node));
    if (opt == NULL) {
        puts("node malloc error!");
        return NULL;
    }
    opt->data = data;
    opt->next = NULL;
    opt->previous = NULL;
    return opt;
}
