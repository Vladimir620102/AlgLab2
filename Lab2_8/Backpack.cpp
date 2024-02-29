#include <iostream>
#include <vector>
#include "goods.h"
#include "backpack.h"


    void Backpack::init(double maxw)
    {
        max_weight = maxw;
    }

    //��������� ����� ��� ������ ���������
    double Backpack::calc_weigth(std::list<Goods> items)
    {
        double sum_weight = 0;

        for(Goods item: items)
        {
            sum_weight += item.weight;
        }

        return sum_weight;
    }

    //��������� ����� ��������� ������ ���������
    double Backpack::calc_price(std::list<Goods> items)
    {
        double sum_price = 0;

        for (Goods item : items)
        {
            sum_price += item.price;
        }

        return sum_price;
    }

    //���������, �������� �� ������ ����� ������ �������� ������
    void Backpack::check_set(std::list<Goods> items)
    {
        if (best_items.size() == NULL)
        {
            if (calc_weigth(items) <= max_weight)
            {
                best_items = items;
                best_price = calc_price(items);
            }
        }
        else
        {
            if (calc_weigth(items) <= max_weight && calc_price(items) > best_price)
            {
                best_items = items;
                best_price = calc_price(items);
            }
        }
    }

    //�������� ���� ������� ������������ ��������
    void Backpack::make_all_sets(std::list<Goods> items)
    {
        if (items.size() > 0)
            check_set(items);

        for (int i = 0; i < items.size(); i++)
        {
            std::list<Goods> newSet = items;

            // ������� i-� ����� ������
            auto it = newSet.begin();
            std::advance(it, i);
            newSet.erase(it);

            make_all_sets(newSet);
        }
    }

    //���������� ����� ��������� � �������
    std::list<Goods> Backpack::get_best_set()
    {
        return best_items;
    }
