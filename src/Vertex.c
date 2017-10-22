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
    printf("index: %d, degree: %d, adjacents: ", v->index, v->degree);
    if (v->degree > 0) {
        for (int i = 0; i < v->degree - 1; i++) {
            printf("%d, ", ((Vertex*)get(v->alist, i))->index);
        }
        printf("%d\n", ((Vertex*)get(v->alist, v->degree - 1))->index);
    } else {
        printf("None\n");
        return 0;
    }
    return 0;
}

int get_degree(Vertex* v, int* opt) {
    if (v == NULL || opt == NULL) {
        puts("get degree NULL ptr");
        return 1;
    }
    *opt = v->degree;
    return 0;
}

int get_index(Vertex* v, int* opt) {
    if (v == NULL || opt == NULL) {
        puts("get index NULL ptr");
        return 1;
    }
    *opt = v->index;
}

LinkedList* get_alist(Vertex* v) {
    if (v == NULL) {
        puts("get alist NULL ptr");
        return NULL;
    }
    return v->alist;
}

int inc_degree(Vertex* v, int offset) {
    if (v == NULL) {
        puts("idegree NULL ptr");
        return 1;
    }
    v->degree += offset;
    return 0;
}

int get_color(Vertex* v, int* opt) {
    if (v == NULL || opt == NULL) {
        puts("get color NULL ptr");
        return 1;
    }
    *opt = v->color;
    return 0;
}

int set_color(Vertex* v, int color) {
    if (v == NULL) {
        puts("set color NULL ptr");
        return 1;
    }
    v->color = color;
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
