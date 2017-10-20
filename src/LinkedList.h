typedef struct LinkedList LinkedList;
typedef struct Node Node;

LinkedList* new_list(void);
int add_list(LinkedList* l, void* data);
void* pop(LinkedList* l);
void* dequeue(LinkedList* l);
void* get(LinkedList* l, int ind);
int get_size(LinkedList* l, int* opt);
int free_list(LinkedList* l);
int print_list(LinkedList* l);
int handle_print(void* data);