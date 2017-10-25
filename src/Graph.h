typedef struct Graph Graph;

Graph* new_Graph(void);//creates a new graph
int init(Graph* g, int num);//initializes a new graph
int add_Vertex(Graph* g);//adds a new vertex
int remove_Vertex(Graph* g, int ind);//removes a vertex
int pick_vertex(Graph* g, int* opt);//picks a vertex to be removed
int add_conn(Graph* g, int from, int to);//adds a connection(directed edge)
int free_Graph(Graph* g);//frees memory occupied
int print_Graph(Graph* g);//prints out a represention
int check_conn(Graph* g, int* opt);//checks whether connected
