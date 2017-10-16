#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vertex.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2

struct Vertex {
    int index;
    int color;
    int degree;
    LinkedList* alist;
};

Vertex* new_Vertex(int index) {
    Vertex* opt = malloc(sizeof(Vertex));
    opt->index = index;
    opt->color = WHITE;
    opt->degree = 0;
    opt->alist = new_list();
}

int add_connection(Vertex* dest, Vertex* src) {
    if (dest == NULL || src == NULL) {
        puts("add connection NULL ptr");
        return 1;
    }
    add_list(dest->alist, src);
    dest->degree += 1;
    return 0;
}

int print_Vertex(Vertex* v) {
    if (v == NULL) {
        puts("print vertex NULL ptr");
        return 1;
    }
    printf("index: %d, adjacents: ", v->index);
    for (int i = 0; i < v->degree - 1; i++) {
        printf("%d, ", ((Vertex*)get(v->alist, i))->index);
    }
    printf("%d\n", ((Vertex*)get(v->alist, v->degree - 1))->index);
    return 0;
}

int free_Vertex(Vertex* v) {
    if (v == NULL) {
        puts("free vertex NULL ptr");
        return 1;
    }
    free_list(v->alist);
    free(v);
    return 0;
}
