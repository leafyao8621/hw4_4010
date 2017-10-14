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

int free_data(Node* n) {
    free_Vertex(get_data(n));
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
}
