typedef struct Graph Graph;

Graph* new_Graph(int size);
int init(Graph* g, int num);
int add_Vertex(Graph* g);
int add_conn(Graph* g, int from, int to);
int free_Graph(Graph* g);
int print_Graph(Graph* g);