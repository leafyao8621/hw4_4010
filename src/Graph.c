#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"
#include "Vertex.h"
#include "LinkedList.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2

struct Graph {
    int max_size;
    int sum_degrees;
    int* degrees;
    LinkedList* nodes;
};

Graph* new_Graph(int size) {
    Graph* opt = malloc(sizeof(Graph));
    if (opt == NULL) {
        puts("graph malloc failure 1");
        return NULL;
    }
    opt->max_size = size;
    opt->sum_degrees = 0;
    opt->degrees = malloc(sizeof(int) * size);
    if (opt->degrees == NULL) {
        puts("graph malloc failure 2");
        return NULL;
    }
    opt->nodes = new_list();
    return opt;
}

int add_Vertex(Graph* g) {
    if (g == NULL) {
        return 1;
    }
    int pos;
    get_size(g->nodes, &pos);
    Vertex* added = new_Vertex(pos);
    add_list(g->nodes, added);
    return 0;
}

int add_conn(Graph* g, int from, int to) {
    add_connection((Vertex*)get(g->nodes, from), (Vertex*)get(g->nodes, to));
}

int init(Graph* g, int num) {
    if (g == NULL) {
        puts("Graph init NULL ptr");
        return 1;
    }
    if (num > g->max_size) {
        puts("graph init num > size");
        return 1;
    }
    for (int i = 0; i < num; i++) {
        add_Vertex(g);
    }
    for (int i = 0; i < num; i++) {
        g->degrees[i] = num - 1;
        for (int j = 0; j < num; j++) {
            if (i != j) {
                add_connection((Vertex*)get(g->nodes, i),
                (Vertex*)get(g->nodes, j));
            }
        }
        g->sum_degrees += (num - 1);
    }
    return 0;
}

int print_Graph(Graph* g) {
    if (g == NULL) {
        puts("print graph NULL ptr");
        return 1;
    }
    int size;
    get_size(g->nodes, &size);
    for (int i = 0; i < size; i++) {
        print_Vertex(get(g->nodes, i));
    }
    return 0;
}

int free_Graph(Graph* g) {
    if (g == NULL) {
        puts("free grph NULL ptr");
        return 1;
    }
    int size;
    get_size(g->nodes, &size);
    for (int i = 0; i < size; i++) {
        free_Vertex(pop(g->nodes));
    }
    free_list(g->nodes);
    return 0;
}
