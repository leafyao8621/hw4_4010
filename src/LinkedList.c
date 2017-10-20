#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "LinkedList.h"

struct LinkedList {
    int size;
    struct Node* head;
    struct Node* tail;
};

struct Node {
    struct Node* next;
    struct Node* previous;
    void* data;
};

Node* new_Node(void* data) {
    Node* opt = malloc(sizeof(Node));
    if (opt == NULL) {
        puts("node malloc error!");
        return NULL;
    }
    opt->data = data;
    opt->next = NULL;
    opt->previous = NULL;
    return opt;
}

LinkedList* new_list(void) {
    LinkedList* opt = malloc(sizeof(LinkedList));
    if (opt == NULL) {
        puts("list malloc error!");
        return NULL;
    }
    opt->head = NULL;
    opt->tail = NULL;
    opt->size = 0;
    return opt;
}

int add_list(LinkedList* l, void* data) {
    if (l == NULL) {
        return 1;
    }
    Node* added = new_Node(data);
    if (l->size == 0) {
        l->head = added;
        l->tail = added;
    } else {
        l->tail->next = added;
        added->previous = l->tail;
        l->tail = added;
    }
    l->size++;
    return 0;
}

void* pop(LinkedList* l) {
    if (l == NULL) {
        puts("pop NULL ptr");
        return NULL;
    }
    if (l->size == 0) {
        puts("no element");
        return NULL;
    }
    if (l->size == 1) {
        void* opt = l->tail->data;
        free(l->tail);
        l->head = NULL;
        l->tail = NULL;
        l->size--;
        return opt;
    }
    void* opt = l->tail->data;
    Node* nt = l->tail->previous;
    free(l->tail);
    l->tail = nt;
    l->tail->next = NULL;
    l->size--;
    return opt;
}

void* dequeue(LinkedList* l) {
    if (l == NULL) {
        puts("dequeue NULL ptr");
        return NULL;
    }
    if (l->size == 0) {
        puts("no element");
        return NULL;
    }
    if (l->size == 1) {
        void* opt = l->head->data;
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->size--;
        return opt;
    }
    void* opt = l->head->data;
    void* nh = l->head->next;
    free(l->head);
    l->head = nh;
    l->head->previous = NULL;
    l->size--;
    return opt;
}

void* get(LinkedList* l, int ind) {
    int tind;
    Node* temp;
    int le;
    if (l == NULL) {
        puts("get NULL ptr");
        return NULL;
    }
    if (ind < 0 || ind >= l->size) {
        puts("get index out of bound");
        return NULL;
    }
    if (ind < l->size / 2) {
        tind = 0;
        temp = l->head;
        le = 1;
    } else {
        tind = l->size - 1;
        temp = l->tail;
        le = 0;
    }
    while (tind != ind) {
        if (le) {
            temp = temp->next;
            tind++;
        } else {
            temp = temp->previous;
            tind--;
        }
    }
    return temp->data;
}

int remove(LinkedList* l, int ind) {
    if (l == NULL) {
        puts("remove NULL ptr");
        return 1;
    }
    if (ind < 0 || ind >= l->size) {
        puts("remove index out of bound");
        return 1;
    }
    if (ind == 0) {
        free(dequeue(l));
        return 0;
    }
    if (ind == l->size - 1) {
        free(pop(l));
        return 0;
    }
    Node* rm = get(l, ind);
    rm->previous->next = rm->next;
    rm->next->previous = rm->previous;
    free(rm);
    return 0;
}

int get_size(LinkedList* l, int* opt) {
    if (l == NULL) {
        puts("get size NULL ptr");
        return 1;
    }
    *opt = l->size;
    return 0;
}

int free_list(LinkedList* l) {
    if (l == NULL) {
        puts("free list NULL ptr");
        return 1;
    }
    Node* temp = l->head;
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        for (int i = id; i < l->size; i+=4) {
            Node* temp1 = temp->next;
            #pragma omp critical
            {
                free(temp);
                temp = temp1;
            }
        }
    }
    free(l);
    return 0;
}

int print_list(LinkedList* l) {
    if (l == NULL) {
        puts("free list NULL ptr");
        return 1;
    }
    Node* temp = l->head;
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        for (int i = id; i < l->size; i+=4) {
            #pragma omp critical
            {
                handle_print(temp->data);
                temp = temp->next;
            }
        }
    }
    return 0;
}