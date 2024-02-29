#pragma once
#include "goods.h"
#include <vector>

struct Backpack
{
    std::list<Goods> best_items;   // набор товаров
//    vector<Goods> best_items;   // набор товаров
    
    double max_weight;          // максимальный вес предметов в рюкзаке
    double best_price;          // лучшая стоимость предметов в рюкзаке
    
    // задает максимальный вес предметов в рюкзаке
    void init(double maxw);
  
    //вычисляет общий вес набора предметов
    double calc_weigth(std::list<Goods> items);
    //double calc_weigth(vector<Goods> items);

    //вычисляет общую стоимость набора предметов
    double calc_price(std::list<Goods> items);
    //double calc_price(vector<Goods> items);

    //проверяет, является ли данный набор лучшим решением задачи
    void check_set(std::list<Goods> items);
    //void check_set(vector<Goods> items);

    //создание всех наборов перестановок значений
    void make_all_sets(std::list<Goods> items);
    //void make_all_sets(vector<Goods> items);

    //возвращает решение задачи (набор предметов)
    std::list<Goods> get_best_set();
    //vector<Goods> get_best_set();
};
