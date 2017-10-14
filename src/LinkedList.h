typedef struct LinkedList LinkedList;

LinkedList* new_list(void);
int add_list(LinkedList* l, void data);
void* pop(LinkedList* l);
void* dequeue(LinkedList* l);
int free_list(LinkedList* l);
