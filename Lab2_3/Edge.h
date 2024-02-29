#pragma once
#include <iostream>

using namespace std;

struct Edge
{
	int start;
	int next;
	int length;

	Edge(int s, int n, int l) {
		start = s;
		next = n;
		length = l;
	}

	void print() {
		cout << start << " - " << next << ": " << length << endl;
	}

	void print_a() {
		cout << static_cast<char>('A' + start ) << " - " << static_cast <char>('A' + next) << ": " << length << endl;
	}
};

struct Node {
	int vertex, length;
	Node(int v, int w) {
		vertex = v;
		length = w;
	}
};