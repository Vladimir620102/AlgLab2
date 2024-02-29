#pragma once
#include "goods.h"
#include <vector>

struct Backpack
{
    std::list<Goods> best_items;   // ����� �������
//    vector<Goods> best_items;   // ����� �������
    
    double max_weight;          // ������������ ��� ��������� � �������
    double best_price;          // ������ ��������� ��������� � �������
    
    // ������ ������������ ��� ��������� � �������
    void init(double maxw);
  
    //��������� ����� ��� ������ ���������
    double calc_weigth(std::list<Goods> items);
    //double calc_weigth(vector<Goods> items);

    //��������� ����� ��������� ������ ���������
    double calc_price(std::list<Goods> items);
    //double calc_price(vector<Goods> items);

    //���������, �������� �� ������ ����� ������ �������� ������
    void check_set(std::list<Goods> items);
    //void check_set(vector<Goods> items);

    //�������� ���� ������� ������������ ��������
    void make_all_sets(std::list<Goods> items);
    //void make_all_sets(vector<Goods> items);

    //���������� ������� ������ (����� ���������)
    std::list<Goods> get_best_set();
    //vector<Goods> get_best_set();
};
