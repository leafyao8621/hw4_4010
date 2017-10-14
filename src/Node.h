typedef struct Node Node;

Node* new_Node(void* data);
void* get_data(Node* n);
int free_data(Node* n);
