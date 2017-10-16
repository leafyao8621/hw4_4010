typedef struct LinkedList LinkedList;
typedef struct Node Node;

Node* new_Node(void* data);
LinkedList* new_list(void);
int add_list(LinkedList* l, void data);
void* pop(LinkedList* l);
void* dequeue(LinkedList* l);
void* get(LinkedList* l, int ind);
int free_list(LinkedList* l);
