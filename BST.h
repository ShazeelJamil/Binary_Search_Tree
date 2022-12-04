#ifndef BST_H
#define BST_H
#include"BSTNode.h"
#include<iostream>
using namespace std;
template<typename T>
class BST
{
	BSTNode<T>* root;
	void insertHelper(BSTNode<T>* p, const T& val);
	bool searchHelper(BSTNode<T>* p, const T& key);
	void LRV(BSTNode<T>* p )
	{
		if (p->left)
			LRV(p->left);
		cout << p->info << "\n";
		if (p->right)
			LRV(p->right);
	}
	//BSTNode<T>* getParent(BSTNode<T>* p, const T& key);
	T removeDegree2Node(BSTNode<T>* ptr);
	void removeElem(T key);
	int heightOfTree(BSTNode<T>* p);
	bool isAVL(BSTNode<T>* p);
public:
	BST();
	void insert(const T& key);
	bool search(const T& key);
	void remove(T val);
	bool checkAVL();
	void postOrder()
	{
		LRV(root);
	}
	

};
template class BST<int>;
#endif // !BST_H
