/* Муравьиный алгоритм для решения задачи коммивояжёра */

#include <locale>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <malloc.h>
using namespace std;

#define N_MIN   5           // минимальное количество вершин
#define N_MAX   20          // максимальное количество вершин

#define Q       100         // количество
#define RHO     0.5         // коэффициент испарения ферромона

// структура ПУТЬ (количество вершин, длина, массив вершин)
struct WAY_TYPE {
    int count;
    int length;
    int* vertex_array;
};

int number_of_iterations;   // количество итераций (10)
int number_of_ants;         // количество муравьев в колонии (7)
double alpha;               // вес фермента (0.5)
double beta;                // коэффициент эвристики (0.5)


// вероятность перехода муравья ant в вершину to
double probability(int to, WAY_TYPE ant, double** pheromone, double** distance, int vertex) {
    // если вершина уже посещена, возвращаем 0
    for (int i = 0; i < ant.count; ++i)
        if (to == ant.vertex_array[i]) return 0;

    double sum = 0.0;
    int from = ant.vertex_array[ant.count - 1];
    // считаем сумму в знаминателе
    for (int j = 0; j < vertex; ++j) {
        int flag = 1;
        // проверяем, посещал ли муравей j вершину
        for (int i = 0; i < ant.count; ++i) if (j == ant.vertex_array[i]) flag = 0;
        // если нет, тогда прибавляем к общей сумме
        if (flag) sum += pow(pheromone[from][j], alpha) * pow(distance[from][j], beta);
    }

    // возвращаем значение вероятности
    return pow(pheromone[from][to], alpha) * pow(distance[from][to], beta) / sum;
}

// основная функция алгоритма поиска
WAY_TYPE AntColonyOptimization(double** distance0, int vertex, int start, int finish) {
    // инициализация данных о лучшем маршруте
    WAY_TYPE way;
    way.count = 0;
    way.length = -1;
    way.vertex_array = new int[vertex];
    // инициализация данных о расстоянии и количестве феромона
    double** distance = NULL, ** pheromone = NULL;

    distance = new double* [vertex];
    pheromone = new double* [vertex];
    for (int i = 0; i < vertex; i++) {
        distance[i] = new double[vertex];
        pheromone[i] = new double[vertex];
        for (int j = 0; j < vertex; ++j) {
            pheromone[i][j] = 1.0 / vertex;
            if (i != j) distance[i][j] = 1.0 / distance0[i][j];
        }
    }

     // инициализация муравьев

    WAY_TYPE *ants = new WAY_TYPE[number_of_ants];

    for (int k = 0; k < number_of_ants; k++) {
        ants[k].count = 0;
        ants[k].length = 0.0;
        //  ants[k].vertex_array = (int*)malloc(sizeof(int) * vertex);
        ants[k].vertex_array = new int[vertex];
        ants[k].vertex_array[ants[k].count++] = start;
    }

    // основной цикл
    for (int t = 0; t < number_of_iterations; t++) {
        // цикл по муравьям
        for (int k = 0; k < number_of_ants; k++) {
            // поиск маршрута для k-го муравья
            do {
                int j_max = -1;
                double p_max = 0.0;
                for (int j = 0; j < vertex; j++) {
                    // Проверка вероятности перехода в вершину j
                    if (ants[k].vertex_array[ants[k].count - 1] != j) {
                        double p = probability(j, ants[k], pheromone, distance, vertex);
                        if (p && p >= p_max) {
                            p_max = p;
                            j_max = j;
                        }
                    }
                }
                ants[k].length += distance0[ants[k].vertex_array[ants[k].count - 1]][j_max];
                ants[k].vertex_array[ants[k].count] = j_max;
            } while (ants[k].vertex_array[ants[k].count++ - 1] != finish);
            // оставляем феромон на пути муравья
            for (int i = 0; i < ants[k].count - 1; i++) {
                int from = ants[k].vertex_array[i % ants[k].count];
                int to = ants[k].vertex_array[(i + 1) % ants[k].count];
                pheromone[from][to] += Q / ants[k].length;
                pheromone[to][from] = pheromone[from][to];
            }
            // проверка на лучшее решение
            if (ants[k].length < way.length || way.length < 0) {
                way.count = ants[k].count;
                way.length = ants[k].length;
                for (int i = 0; i < way.count; ++i) way.vertex_array[i] = ants[k].vertex_array[i];
            }
            // обновление муравьев
            ants[k].count = 1;
            ants[k].length = 0.0;
        }
        // цикл по ребрам
        for (int i = 0; i < vertex; i++)
            for (int j = 0; j < vertex; j++)
                // обновление феромона для ребра (i, j)
                if (i != j) pheromone[i][j] *= (1 - RHO);
    }

    for (int i = 0; i < vertex; i++) {
        delete pheromone[i];
        delete distance[i];
    }
    delete []distance;
    delete []pheromone;

    // возвращаем кратчайший маршрут
    return way;
}


void init_distances(double** D, int N)
{
    //          Тестовая матрица
    /*
    int[, ] data = {
        { 0, 25, 40, 31, 27},
        { 5,  0,  17, 30, 25 },
        {19, 15,  0,  6,  1},
        { 9, 50, 24,  0,  6 },
        {22,  8,  7, 10,  0 }
    };
    */

    D[0][0] = 0;  D[0][1] = 25; D[0][2] = 40; D[0][3] = 31; D[0][4] = 27;
    D[1][0] = 5;  D[1][1] = 0;  D[1][2] = 17; D[1][3] = 30; D[1][4] = 25;
    D[2][0] = 19; D[2][1] = 15; D[2][2] = 0;  D[2][3] = 6;  D[2][4] = 1;
    D[3][0] = 9;  D[3][1] = 50; D[3][2] = 24; D[3][3] = 0;  D[3][4] = 6;
    D[4][0] = 22; D[4][1] = 8;  D[4][2] = 7;  D[4][3] = 10; D[4][4] = 0;
    
    cout << "Матрица расстояний:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << "\t" << D[i][j];
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    double** D = NULL;
    int N = 0, A = 0, B = 0;
    // инициализация матрицы расстояний
    while (N < N_MIN || N > N_MAX) {
        cout << "Введите количество вершин [" << N_MIN << ", " << N_MAX << "]: "; cin >> N;
    }
    
    D = new double *[N];
    for (int i = 0; i < N; i++)
        D[i] = new double[N];

    init_distances(D, N);

    // инициализация начальной и конечной точек
    while (A < 1 || A > N) {
        cout << "Введите начальную вершину от 1 до " << N << ": "; cin >> A;
    }
    while (B < 1 || B > N || B == A) {
        cout << "Введите конечную вершину от 1 до " << N << " исключая " << A << ": "; cin >> B;
    }

    cout << "Введите количество муравьев: "; cin >> number_of_ants;
    cout << "Введите количество итераций: "; cin >> number_of_iterations;

    cout << "Введите вес фермента: ";           cin >> alpha;
    cout << "Введите коэффициент эвристики: ";  cin >> beta;

    // запускаем алгоритм
    WAY_TYPE way = AntColonyOptimization(D, N, --A, --B);

    // выводим результат
    cout << "Длина пути: " << way.length << endl;
    cout << "Путь: " << ++way.vertex_array[0];
    for (int i = 1; i < way.count; ++i) cout << " -> " << ++way.vertex_array[i];

    for (int i = 0; i < N; i++)
        delete D[i];
    delete []D;

    return 0;
}