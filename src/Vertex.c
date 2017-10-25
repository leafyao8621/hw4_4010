#include <stdio.h>
#include <stdlib.h>
#include "Vertex.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2

/**
 * Represents a vertex in a graph
 * @param  index  index in the graph
 * @param  color  color of the vertex(used in bfs)
 * @param  degree degree of the vertex
 * @param  alist  adjacency list of the vertex
 */
struct Vertex {
    int index;
    int color;
    int degree;
    LinkedList* alist;
};

/**
 * creates a pointer to a vertex
 * @param  index index of the vertex to be created
 * @return       a new pointer to a vertex
 */
Vertex* new_Vertex(int index) {
    Vertex* opt = malloc(sizeof(Vertex));
    opt->index = index;
    opt->color = WHITE;
    opt->degree = 0;
    opt->alist = new_list();
    return opt;
}

/**
 * add a connection from dest to src
 * @param  dest connection from
 * @param  src  connection to
 * @return      whether successful
 */
int add_connection(Vertex* dest, Vertex* src) {
    if (dest == NULL || src == NULL) {
        puts("add connection NULL ptr");
        return 1;
    }
    add_list(dest->alist, src);
    dest->degree += 1;
    return 0;
}

/**
 * prints the contents of a vertex
 * @param  v a pointer to the vertex to be printed
 * @return   whether successful
 */
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

/**
 * gets the degree of a vertex
 * @param  v   a pointer to the vertex of interest
 * @param  opt a pointer to the variable the result will be put in
 * @return     whether successful
 */
int get_degree(Vertex* v, int* opt) {
    if (v == NULL || opt == NULL) {
        puts("get degree NULL ptr");
        return 1;
    }
    *opt = v->degree;
    return 0;
}

/**
 * gets the index of a vertex
 * @param  v   a pointer to the vertex of interest
 * @param  opt a pointer to the variable the result will be put in
 * @return     whether successful
 */
int get_index(Vertex* v, int* opt) {
    if (v == NULL || opt == NULL) {
        puts("get index NULL ptr");
        return 1;
    }
    *opt = v->index;
}

/**
 * gets the adjacency list of a vertex
 * @param  v a pointer to the vertex of interest
 * @return   the adjacency list; NULL on failure
 */
LinkedList* get_alist(Vertex* v) {
    if (v == NULL) {
        puts("get alist NULL ptr");
        return NULL;
    }
    return v->alist;
}

/**
 * increments the degree of a vertex by offset
 * @param  v      a pointer to the vertex of interest
 * @param  offset the offset
 * @return        whether successful
 */
int inc_degree(Vertex* v, int offset) {
    if (v == NULL) {
        puts("idegree NULL ptr");
        return 1;
    }
    v->degree += offset;
    return 0;
}

/**
 * gets color of the vertex
 * @param  v   a pointer to the vertex of interest
 * @param  opt [description]
 * @return     [description]
 */
int get_color(Vertex* v, int* opt) {
    if (v == NULL || opt == NULL) {
        puts("get color NULL ptr");
        return 1;
    }
    *opt = v->color;
    return 0;
}

/**
 * sets the color of a vertex
 * @param  v     a pointer to the vertex of interest
 * @param  color the color to be set
 * @return       whether successful
 */
int set_color(Vertex* v, int color) {
    if (v == NULL) {
        puts("set color NULL ptr");
        return 1;
    }
    v->color = color;
    return 0;
}

/**
 * frees all memory occupied due to using a vertex pointer
 * @param  v a pointer to the vertex of interest
 * @return   whether successful
 */
int free_Vertex(Vertex* v) {
    if (v == NULL) {
        puts("free vertex NULL ptr");
        return 1;
    }
    free_list(v->alist);
    free(v);
    return 0;
}
