// TestProbe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>

long long factorial(int n);
using namespace std;
int main()
{
    
    list<int> goods = { 10,20,30,40,50,60 };

    for (auto item : goods)
        cout << item << " ";
    cout << endl;


    auto it = goods.begin();
    advance(it, 2);
    goods.erase(it);
//    goods.erase(advance(goods.begin(), 2));

    for (auto item : goods)
        cout << item << " ";
    cout << endl;

}

long long factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}
