#include<iostream>
#include "Tree.h"



int main()
{
	Tree234 tree234 = Tree234();
	tree234.insert(10);
	tree234.insert(14);
	tree234.insert(18);
	tree234.insert(20);
	tree234.insert(25);		
	tree234.insert(32);
	tree234.insert(33);	
	tree234.insert(40);
	tree234.insert(42);
	tree234.insert(43);
	tree234.insert(47);
	tree234.insert(50);
	tree234.insert(52);
	tree234.insert(62);
	tree234.insert(65);
	tree234.insert(70);
	tree234.insert(74);
	tree234.insert(79);
	tree234.insert(81);

	tree234.travel();
	std::cout << std::endl;
	std::cout << "\ninsert 60\n";
	tree234.insert(60);
	//tree234.remove(70);
	tree234.travel();
	std::cout << std::endl;
	//tree234.remove(7);
	std::cout << "\nremove 47\n";
	tree234.remove(47);
	tree234.travel();
	std::cout << std::endl;
	tree234.remove(100);
	//Tree234Node *t = tree234.search(14);
	//t->travel();
	return 0;
}


