#include <iostream>
#include "Graph.h"
#include <vector>
#include "Edge.h"
#include <queue>

using namespace std;

void printPath(vector<int> const& prev, int i, int start)
{
    if (i < 0) {
        return;
    }
    printPath(prev, prev[i], start);
    if (i != start) {
        cout << ", ";
    }
    cout << i;
}

//// ������ ���������, ������� ����� �������������� ��� �������������� ����
//struct comp
//{
//    bool operator()(const Node& lhs, const Node& rhs) const {
//        return lhs.length> rhs.length;
//    }
//};

// ��������� �������� �������� �� �������� Graph
void findShortestPaths(Graph const& graph, int start, int n)
{
    // ������� ����-���� � ������������ �������� ���� � ����������� 0
    priority_queue<Node, vector<Node>, comp> min_heap;
    min_heap.push({ start, 0 });

    // ������������� ��������� ���������� �� ��������� �� `v` ��� �������������
    vector<int> dist(n, INT_MAX);

    // ���������� �� ��������� �� ���� ����� ����
    dist[start] = 0;

    // ���������� ������ ��� ������������ ������, ��� ������� �������
    // ��������� ��� �������
    vector<bool> done(n, false);
    done[start] = true;

    // ��������� ���������� ������� (� ���� ������)
    vector<int> prev(n, -1);

    // �������� �� ��� ���, ���� ����-���� �� ������ ������
    while (!min_heap.empty())
    {
        // ������� � ������� ������ �������
        Node node = min_heap.top();
        min_heap.pop();

        // �������� ����� �������
        int u = node.vertex;

        // ������ ��� ������� ������ `v` �� `u`
        for (auto i : graph.adjList[u])
        {
            int v = i.next;
            int length = i.length;

            // ��� ����������
            if (!done[v] && (dist[u] + length) < dist[v])
            {
                dist[v] = dist[u] + length;
                prev[v] = u;
                min_heap.push({ v, dist[v] });
            }
        }

        // �������� ������� `u` ��� �����������, ����� ��� ������ �� �����������
        done[u] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != start && dist[i] != INT_MAX)
        {
            cout << "Path (" << start << " �> " << i << "): Minimum cost = "
                << dist[i] << ", Route = [";
            printPath(prev, i, start);
            cout << "]" << endl;
        }
    }
}