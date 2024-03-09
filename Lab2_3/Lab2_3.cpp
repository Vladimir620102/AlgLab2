// Lab2_3 Алгоритм Дейкстры

#include <iostream>
#include <vector>
#include "Edge.h"
#include "Graph.h"

int main()
{
    vector<Edge> edges =
    {
        {0, 1, 7}, {0, 2, 10}, 
        {1, 5, 9}, {1, 6, 27}, 
        {2, 4, 31}, {2, 5, 8}, 
        {3, 4, 32}, {3, 7, 17}, {3, 8, 21},
        {5, 7, 11}, 
        {6, 8, 15}, 
        {7, 8, 15}
    };

    for (Edge o : edges) {
        o.print_a();
    }

    // общее количество узлов в Graph
    int n = 9;

    // построить Graph
    Graph graph(edges, n);

    // запускаем алгоритм Дейкстры с каждого узла
    for (int source = 0; source < n; source++) {
        findShortestPaths(graph, source, n);
    }

}
