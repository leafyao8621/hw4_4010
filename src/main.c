#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main() {
    Graph* g = new_Graph(1000);
    init(g, 5);
    print_Graph(g);
    free_Graph(g);
    return 0;
}
