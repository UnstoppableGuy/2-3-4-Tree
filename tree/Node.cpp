#include "Node.h"
#include <iostream>

Tree234Node::Tree234Node(int t1, bool leaf1)
{
	t = 2;
	leaf = leaf1;
	keys = new int[3];
	nodes = new Tree234Node * [4];
	count = 0;
}

int Tree234Node::findKey(int k)
{
	int idx = 0;
	while (idx < count && keys[idx] < k)
		++idx;
	return idx;
}

void Tree234Node::remove(int k)
{
	int idx = findKey(k);
	if (idx < count && keys[idx] == k)
	{
		if (leaf)
			removeFromLeaf(idx);
		else
			removeFromNonLeaf(idx);
	}
	else
	{
		if (leaf)
		{
			std::cout << "The key " << k << " is does not exist in the tree\ncount";
			return;
		}
		bool flag = ((idx == count) ? true : false);
		if (nodes[idx]->count < t)
			fill(idx);
		if (flag && idx > count)
			nodes[idx - 1]->remove(k);
		else
			nodes[idx]->remove(k);
	}
	return;
}

void Tree234Node::removeFromLeaf(int idx)
{
	for (int i = idx + 1; i < count; ++i)
		keys[i - 1] = keys[i];
	count--;
	return;
}

void Tree234Node::removeFromNonLeaf(int idx)
{
	int k = keys[idx];
	if (nodes[idx]->count >= t)
	{
		int pred = getPredecessor(idx);
		keys[idx] = pred;
		nodes[idx]->remove(pred);
	}
	else if (nodes[idx + 1]->count >= t)
	{
		int succ = getSuccessor(idx);
		keys[idx] = succ;
		nodes[idx + 1]->remove(succ);
	}
	else
	{
		merge(idx);
		nodes[idx]->remove(k);
	}
	return;
}

int Tree234Node::getPredecessor(int idx)
{
	Tree234Node* cur = nodes[idx];
	while (!cur->leaf)
		cur = cur->nodes[cur->count];
	return cur->keys[cur->count - 1];
}

int Tree234Node::getSuccessor(int idx)
{
	Tree234Node* cur = nodes[idx + 1];
	while (!cur->leaf)
		cur = cur->nodes[0];
	return cur->keys[0];
}

void Tree234Node::fill(int idx)
{
	if (idx != 0 && nodes[idx - 1]->count >= t)
		borrowFromPrev(idx);
	else if (idx != count && nodes[idx + 1]->count >= t)
		borrowFromNext(idx);
	else
	{
		if (idx != count)
			merge(idx);
		else
			merge(idx - 1);
	}
	return;
}

void Tree234Node::borrowFromPrev(int idx)
{
	Tree234Node* child = nodes[idx];
	Tree234Node* sibling = nodes[idx - 1];
	for (int i = child->count - 1; i >= 0; --i)
		child->keys[i + 1] = child->keys[i];
	if (!child->leaf)
	{
		for (int i = child->count; i >= 0; --i)
			child->nodes[i + 1] = child->nodes[i];
	}
	child->keys[0] = keys[idx - 1];
	if (!child->leaf)
		child->nodes[0] = sibling->nodes[sibling->count];
	keys[idx - 1] = sibling->keys[sibling->count - 1];
	child->count += 1;
	sibling->count -= 1;
	return;
}

void Tree234Node::borrowFromNext(int idx)
{
	Tree234Node* child = nodes[idx];
	Tree234Node* sibling = nodes[idx + 1];
	child->keys[(child->count)] = keys[idx];
	if (!(child->leaf))
		child->nodes[(child->count) + 1] = sibling->nodes[0];
	keys[idx] = sibling->keys[0];
	for (int i = 1; i < sibling->count; ++i)
		sibling->keys[i - 1] = sibling->keys[i];
	if (!sibling->leaf)
	{
		for (int i = 1; i <= sibling->count; ++i)
			sibling->nodes[i - 1] = sibling->nodes[i];
	}
	child->count += 1;
	sibling->count -= 1;
	return;
}

void Tree234Node::merge(int idx)
{
	Tree234Node* child = nodes[idx];
	Tree234Node* sibling = nodes[idx + 1];
	child->keys[t - 1] = keys[idx];
	for (int i = 0; i < sibling->count; ++i)
		child->keys[i + t] = sibling->keys[i];
	if (!child->leaf)
	{
		for (int i = 0; i <= sibling->count; ++i)
			child->nodes[i + t] = sibling->nodes[i];
	}
	for (int i = idx + 1; i < count; ++i)
		keys[i - 1] = keys[i];
	for (int i = idx + 2; i <= count; ++i)
		nodes[i - 1] = nodes[i];
	child->count += sibling->count + 1;
	count--;
	delete(sibling);
	return;
}
void Tree234Node::insertNonFull(int k)
{
	int i = count - 1;
	if (leaf == true)
	{
		while (i >= 0 && keys[i] > k)
		{
			keys[i + 1] = keys[i];
			i--;
		}
		keys[i + 1] = k;
		count = count + 1;
	}
	else
	{
		while (i >= 0 && keys[i] > k)
			i--;
		if (nodes[i + 1]->count == 3)
		{
			splitChild(i + 1, nodes[i + 1]);
			if (keys[i + 1] < k)
				i++;
		}
		nodes[i + 1]->insertNonFull(k);
	}
}

void Tree234Node::splitChild(int i, Tree234Node* y)
{
	Tree234Node* z = new Tree234Node(y->t, y->leaf);
	z->count = t - 1;
	for (int j = 0; j < t - 1; j++)
		z->keys[j] = y->keys[j + t];
	if (y->leaf == false)
	{
		for (int j = 0; j < t; j++)
			z->nodes[j] = y->nodes[j + t];
	}
	y->count = t - 1;
	for (int j = count; j >= i + 1; j--)
		nodes[j + 1] = nodes[j];
	nodes[i + 1] = z;
	for (int j = count - 1; j >= i; j--)
		keys[j + 1] = keys[j];
	keys[i] = y->keys[t - 1];
	count = count + 1;
}

void Tree234Node::travel()
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (leaf == false)
			nodes[i]->travel();
		std::cout << " " << keys[i];
	}
	if (leaf == false)
		nodes[i]->travel();
}

Tree234Node* Tree234Node::search(int k)
{
	int i = 0;
	while (i < count && k > keys[i])
		i++;
	if (keys[i] == k)
		return this;
	if (leaf == true)
		return nullptr;
	return nodes[i]->search(k);
}