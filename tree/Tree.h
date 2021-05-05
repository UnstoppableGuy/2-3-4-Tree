#pragma once
#include <cstddef>
#include "Node.h"
class Tree234
{
	Tree234Node* root = nullptr;
	int t = 2;
public:

	Tree234();

	Tree234(int _t);

	void travel();

	Tree234Node* search(int k);

	void insert(int k);

	void remove(int k);

};

