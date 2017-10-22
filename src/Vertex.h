#include "LinkedList.h"
typedef struct Vertex Vertex;

Vertex* new_Vertex(int index);
int add_connection(Vertex* dest, Vertex* src);
int get_index(Vertex* v, int* opt);
int get_degree(Vertex* v, int* opt);
LinkedList* get_alist(Vertex* v);
int inc_degree(Vertex* v, int offset);
int free_Vertex(Vertex* v);
int print_Vertex(Vertex* v);
int get_color(Vertex* v, int* opt);
int set_color(Vertex* v, int color);
