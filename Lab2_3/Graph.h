#pragma once
#include <iostream>
#include <vector>

#include "Edge.h"

using namespace std;


class Graph {
public:
    // вектор векторов `Edge` для представления списка смежности
    vector<vector<Edge>> adjList;

    // Конструктор Graphа
    Graph(vector<Edge> const& edges, int n)
    {
        // изменить размер вектора, чтобы он содержал `n` элементов типа vector<Edge>
        adjList.resize(n);

        // добавляем ребра в ориентированный graph
        for (Edge const& edge : edges)
        {
            // вставляем в конце
            adjList[edge.start].push_back(edge);
        }
    }
};

void printPath(vector<int> const& prev, int i, int start);

struct comp
{
    bool operator()(const Node& lhs, const Node& rhs) const {
        return lhs.length > rhs.length;
    }
};

void findShortestPaths(Graph const& graph, int start, int n);
