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
}

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
    Vertex* added = new_Vertex(g->list->size);
    add_list(g->list, added);
    return 0;
}

int add_conn(Graph* g, int from, int to) {
    add_connection((Vertex*)get(g->list, from), (Vertex*)get(g->list, to));
}

int init(Graph* g, int num) {
    if (g == NULL) {
        puts("Graph init NULL ptr");
        return 1;
    }
    if (num > g->size) {
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
                add_connection((Vertex*)get(g->list, i),
                (Vertex*)get(g->list, j));
            }
        }
        g->sum_degrees += num - 1;
    }
    return 0;
}
