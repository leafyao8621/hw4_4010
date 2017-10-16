typedef struct Vertex Vertex;

Vertex* new_Vertex(int index);
int add_connection(Vertex* dest, Vertex* src);
int free_Vertex(Vertex* v);
int print_Vertex(Vertex* v);