#pragma once
#include <iostream>
#include <vector>

#include "Edge.h"

using namespace std;


class Graph {
public:
    // ������ �������� `Edge` ��� ������������� ������ ���������
    vector<vector<Edge>> adjList;

    // ����������� Graph�
    Graph(vector<Edge> const& edges, int n)
    {
        // �������� ������ �������, ����� �� �������� `n` ��������� ���� vector<Edge>
        adjList.resize(n);

        // ��������� ����� � ��������������� graph
        for (Edge const& edge : edges)
        {
            // ��������� � �����
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
