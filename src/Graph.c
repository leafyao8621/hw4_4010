#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"
#include "LinkedList.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2

struct Graph {
    int sum_degrees;
    int* degrees;
    LinkedList* nodes;
}
