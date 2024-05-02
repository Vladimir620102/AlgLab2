// Lab2_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

#include "goods.h"
#include "backpack.h"

using namespace std;

int WEIGHT_MAX = 10;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    list<Goods> goods;
    goods = init_goods(goods);
    show_items(goods);

    Backpack bp;
    bp.init(WEIGHT_MAX);

    bp.make_all_sets(goods);

    cout << endl;

    list<Goods> solve = bp.get_best_set();

    show_items(solve);
    return 0;
}

void show_items(list<Goods> items)
{
    cout << "Название   "<< "\t\t\t" << "Вес" << "\t" << "Стоимость" << endl;

    for (Goods item : items)
    {
        cout << item.name << "\t" << item.weight << "\t" << item.price << endl;
    }
}



