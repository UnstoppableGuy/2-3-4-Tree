#pragma once

class Tree234Node
{
	int* keys;
	int t;
	Tree234Node** nodes;
	int count;
	bool leaf; // Is true when node is leaf. Otherwise false

public:

	Tree234Node(int _t, bool _leaf);

	void travel();

	Tree234Node* search(int k);

	int findKey(int k);

	void insertNonFull(int k);

	void splitChild(int i, Tree234Node* y);

	void remove(int k);

	void removeFromLeaf(int idx);

	void removeFromNonLeaf(int idx);

	int getPredecessor(int idx);

	int getSuccessor(int idx);

	void fill(int idx);

	void borrowFromPrev(int idx);

	void borrowFromNext(int idx);

	void merge(int idx);

	friend class Tree234;
};


