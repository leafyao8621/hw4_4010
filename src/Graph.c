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
    add_connection(get())
}

int init(int num) {

}
