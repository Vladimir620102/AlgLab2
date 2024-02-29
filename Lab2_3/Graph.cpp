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

//// Объект сравнения, который будет использоваться для упорядочивания кучи
//struct comp
//{
//    bool operator()(const Node& lhs, const Node& rhs) const {
//        return lhs.length> rhs.length;
//    }
//};

// Запускаем алгоритм Дейкстры на заданном Graph
void findShortestPaths(Graph const& graph, int start, int n)
{
    // создаем мини-кучу и проталкиваем исходный узел с расстоянием 0
    priority_queue<Node, vector<Node>, comp> min_heap;
    min_heap.push({ start, 0 });

    // устанавливаем начальное расстояние от источника на `v` как бесконечность
    vector<int> dist(n, INT_MAX);

    // расстояние от источника до себя равно нулю
    dist[start] = 0;

    // логический массив для отслеживания вершин, для которых минимум
    // стоимость уже найдена
    vector<bool> done(n, false);
    done[start] = true;

    // сохраняет предыдущую вершину (в путь печати)
    vector<int> prev(n, -1);

    // работать до тех пор, пока мини-куча не станет пустой
    while (!min_heap.empty())
    {
        // Удалить и вернуть лучшую вершину
        Node node = min_heap.top();
        min_heap.pop();

        // получаем номер вершины
        int u = node.vertex;

        // делаем для каждого соседа `v` из `u`
        for (auto i : graph.adjList[u])
        {
            int v = i.next;
            int length = i.length;

            // Шаг релаксации
            if (!done[v] && (dist[u] + length) < dist[v])
            {
                dist[v] = dist[u] + length;
                prev[v] = u;
                min_heap.push({ v, dist[v] });
            }
        }

        // помечаем вершину `u` как выполненную, чтобы она больше не поднималась
        done[u] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != start && dist[i] != INT_MAX)
        {
            cout << "Path (" << start << " —> " << i << "): Minimum cost = "
                << dist[i] << ", Route = [";
            printPath(prev, i, start);
            cout << "]" << endl;
        }
    }
}