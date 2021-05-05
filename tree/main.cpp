#include<iostream>
#include "Tree.h"
using namespace std;


int main()
{
	Tree234 tree234 = Tree234();
	tree234.insert(10);
	tree234.insert(14);
	tree234.insert(18);
	tree234.insert(20);
	tree234.insert(25);
	tree234.insert(33);
	tree234.insert(32);
	tree234.insert(33);
	tree234.insert(40);
	tree234.insert(43);
	tree234.insert(42);
	tree234.insert(47);
	tree234.insert(50);
	tree234.insert(57);
	tree234.insert(62);
	tree234.insert(70);
	tree234.insert(65);
	tree234.insert(74);
	tree234.insert(79);
	tree234.insert(84);
	tree234.travel();
	std::cout << std::endl;
	tree234.insert(60);
	tree234.travel();
	std::cout << std::endl;

	return 0;
}


