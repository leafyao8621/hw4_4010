#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"
#include "Vertex.h"

int main(int argc, const char** argv) {
    srand(time(NULL));
    Graph* g = new_Graph();
    if (argc < 3) {
        puts("insufficient number of args");
        return 1;
    }
    int initial_size = atoi(argv[1]);
    if (initial_size <= 0) {
        puts("invalid initial size");
        return 1;
    }
    int add = atoi(argv[2]);
    if (add <= 0) {
        puts("invalid additional size");
        return 1;
    }
    init(g, initial_size);
    for (int i = 0; i < add; i++) {
        add_Vertex(g);
        int picked;
        pick_vertex(g, &picked);
        add_conn(g, initial_size + i, picked);
        add_conn(g, picked, initial_size + i);
    }
    if (argc == 4) {
        print_Graph(g);
        puts("");
    }
    int connected;
    check_conn(g, &connected);
    int size = initial_size + add;
    int count = 0;
    while (size > 1 && connected) {
        int ind = ((double)rand()) / RAND_MAX * size;
        remove_Vertex(g, ind);
        check_conn(g, &connected);
        size--;
        if (argc == 4) {
            printf("remove %d\n", ind);
            print_Graph(g);
            puts("");
        }
        count++;
    }
    printf("%d\n", count);
    free_Graph(g);
    return 0;
}
