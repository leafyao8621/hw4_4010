typedef struct Graph Graph;

Graph* new_Graph(void);
int init(Graph* g, int num);
int add_Vertex(Graph* g);
int remove_Vertex(Graph* g, int ind);
int pick_vertex(Graph* g, int* opt);
int add_conn(Graph* g, int from, int to);
int free_Graph(Graph* g);
int print_Graph(Graph* g);
int check_conn(Graph* g, int* opt);
