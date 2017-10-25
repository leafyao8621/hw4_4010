#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Vertex.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2

/**
 * represents a graph
 * @param sum_degrees sum of degrees
 * @param nodes       linked list of vertices
 */
struct Graph {
    int sum_degrees;
    LinkedList* nodes;
};

/**
 * implementation of the print handler function used in print_list
 * @param  data the data to be printed
 * @return      whether successful
 */
int handle_print(void* data) {
    if (data == NULL) {
        puts("handle print NULL ptr");
        return 1;
    }
    print_Vertex((Vertex*)data);
    return 0;
}

/**
 * creates a new graph
 * @return  a pointer to the newly created graph
 */
Graph* new_Graph(void) {
    Graph* opt = malloc(sizeof(Graph));
    if (opt == NULL) {
        puts("graph malloc failure 1");
        return NULL;
    }
    opt->sum_degrees = 0;
    opt->nodes = new_list();
    return opt;
}

/**
 * adds a vertex to a graph
 * @param  g a pointer to the graph of interest
 * @return   whether successful
 */
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

/**
 * adds a connection from a vertex to another in a graph
 * @param  g    a pointer to the graph of interest
 * @param  from index of the from node
 * @param  to   index of the to node
 * @return      whether successful
 */
int add_conn(Graph* g, int from, int to) {
    add_connection((Vertex*)get(g->nodes, from), (Vertex*)get(g->nodes, to));
    g->sum_degrees += 1;
}

/**
 * removes a vertex from a graph
 * @param  g   a pointer to the graph of interest
 * @param  ind current index of the vertex in the linked list of vertices
 * @return     whether successful
 */
int remove_Vertex(Graph* g, int ind) {
    Vertex* rm = get(g->nodes, ind);
    int sind;
    get_index(rm, &sind);
    int rmdeg;
    get_degree(rm, &rmdeg);
    g->sum_degrees -= rmdeg;
    int size;
    get_size(g->nodes, &size);
    //cleans up the vertex's existence in all adjacency lists, and sets sum of
    //degrees accordingly
    for (int i = 0; i < size; i++) {
        if (i != ind) {
            Vertex* v = get(g->nodes, i);
            int deg;
            get_degree(v, &deg);
            LinkedList* cl = get_alist(v);
            for (int j = 0; j < deg; j++) {
                Vertex* chk = get(cl, j);
                int cind;
                get_index(chk, &cind);
                if (cind == sind) {
                    remove_ind(cl, j);
                    inc_degree(v, -1);
                    g->sum_degrees--;
                    break;
                }
            }
        }
    }
    free_Vertex(rm);
    remove_ind(g->nodes, ind);
    return 0;
}

/**
 * picks the index of a vertex to be removed from a graph using the empirical cd
 * f based on the degrees of the nodes in a graph
 * @param  g   a pointer to the graph of interest
 * @param  opt a pointer to the variable to put the result in
 * @return     whether successful
 */
int pick_vertex(Graph* g, int* opt) {
    if (g == NULL || opt == NULL) {
        puts("pick vertex NULL ptr");
        return 1;
    }
    double max = (double)g->sum_degrees;
    double num = (double)rand() / RAND_MAX;
    int i = 0;
    int qi;
    get_degree(get(g->nodes, 0), &qi);
    while ((qi / max) < num) {
        int temp;
        get_degree(get(g->nodes, ++i), &temp);
        qi += temp;
    }
    *opt = i;
    return 0;
}

/**
 * initialize a graph to have a certain number of vertices, fully connected
 * @param  g   a pointer to the graph of interest
 * @param  num initial number of vertices
 * @return     whether successful
 */
int init(Graph* g, int num) {
    if (g == NULL) {
        puts("Graph init NULL ptr");
        return 1;
    }
    for (int i = 0; i < num; i++) {
        add_Vertex(g);
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i != j) {
                add_conn(g, i, j);
            }
        }
    }
    return 0;
}

/**
 * prints out a representation of a graph
 * @param  g a pointer to the graph of interest
 * @return   whether successful
 */
int print_Graph(Graph* g) {
    if (g == NULL) {
        puts("print graph NULL ptr");
        return 1;
    }
    printf("sum of degrees: %d\n", g->sum_degrees);
    print_list(g->nodes);
    return 0;
}

/**
 * frees memory occupied by a graph
 * @param  g a pointer to the graph of interest
 * @return   whether successful
 */
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

/**
 * checks whether a graph is connected using a bfs
 * @param  g   a pointer to the graph of interest
 * @param  opt a pointer to the varible to put the output in
 * @return     whether successful
 */
int check_conn(Graph* g, int* opt) {
    if (g == NULL || opt == NULL) {
        puts("check conn NULL ptr");
        return 1;
    }
    LinkedList* queue = new_list();
    Vertex* v = get(g->nodes, 0);
    if (v == NULL) {
        *opt = 1;
        return 0;
    }
    int num_v;
    get_size(g->nodes, &num_v);
    int size = 1;
    int cnt = 0;
    add_list(queue, v);
    while (size != 0) {
        cnt++;
        Vertex* visited = dequeue(queue);
        set_color(visited, BLACK);
        int degree;
        get_degree(visited, &degree);
        LinkedList* alist = get_alist(visited);
        for (int i = 0; i < degree; i++) {
            Vertex* temp = get(alist, i);
            int color;
            get_color(temp, &color);
            if (color == WHITE) {
                set_color(temp, GRAY);
                add_list(queue, temp);
            }
        }
        get_size(queue, &size);
    }
    for (int i = 0; i < num_v; i++) {
        set_color(get(g->nodes, i), WHITE);
    }
    free_list(queue);
    *opt = cnt == num_v;
    return 0;
}
