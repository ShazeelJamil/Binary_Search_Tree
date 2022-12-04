#ifndef BST_NODE_H
#define BST_NODE_H
template<typename T>
struct BSTNode
{
	T info;
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode()
	{
		left = nullptr;
		right = nullptr;
	}
	BSTNode(T val)
	{
		info = val;
		left = nullptr;
		right = nullptr;
	}
};

#endif // !BST_NODE_H
