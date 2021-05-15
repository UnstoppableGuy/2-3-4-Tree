#include "Tree.h"
#include <iostream>
#include "Node.h"

Tree234::Tree234()
{
}

Tree234::Tree234(int _t)
{
	root = nullptr;
	t = _t;
}

void Tree234::travel()
{
	if (root != nullptr) root->travel();
}

Tree234Node* Tree234::search(int k)
{
	return (root == nullptr) ? nullptr : root->search(k);
}

void Tree234::insert(int k)
{
	if (root == nullptr)
	{
		root = new Tree234Node(t, true);
		root->keys[0] = k;
		root->count = 1;
	}
	else
	{
		if (root->count == 3)
		{
			Tree234Node* s = new Tree234Node(t, false);
			s->nodes[0] = root;
			s->splitChild(0, root);
			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->nodes[i]->insertNonFull(k);
			root = s;
		}
		else
			root->insertNonFull(k);
	}
}

void Tree234::remove(int k)
{
	if (!root)
	{
		std::cout << "The tree is empty";
		return;
	}
	root->remove(k);
	if (root->count == 0)
	{
		Tree234Node* tmp = root;
		if (root->leaf)
			root = nullptr;
		else
			root = root->nodes[0];
		delete tmp;
	}
	return;
}
