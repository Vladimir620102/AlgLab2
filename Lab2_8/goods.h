#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int NUM_GOODS = 8;

struct Goods
{
	string name;
	float price;
	float weight;
	void init(string n, float w, float p) {
		name = n;
		weight = w;
		price = p;
	}
};

std::list<Goods> init_goods(std::list<Goods> goods);
void show_items(std::list<Goods> items);

//vector<Goods> init_goods(vector<Goods> goods);
//void show_items(vector<Goods> items);