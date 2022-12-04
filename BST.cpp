#include"BST.h"
template<typename T>
BST<T>::BST()
{
	root = nullptr;
}
template<typename T>
void BST<T>::insert(const T& val)
{
	if (!root)
	{
		root = new BSTNode<T>(val);
		return;
	}
	insertHelper(root, val);
}
template<typename T>
void BST<T>::insertHelper(BSTNode<T>* p, const T& val)
{
	bool status = false;
	if (val < p->info && p->left)
	{
		status = true;
		insertHelper(p->left, val);
		return;
	}
	if (!status && val > p->info && p->right)
	{
		insertHelper(p->right, val);
		return;
	}
	if (p->info > val)
		p->left = new BSTNode<T>(val);
	else
		p->right = new BSTNode<T>(val);
}
template<typename T>
bool BST<T>::search(const T& key)
{
	return searchHelper(root,key);
}
template<typename T>
bool BST<T>::searchHelper(BSTNode<T>* p, const T& key)
{
	if (p->info == key)
		return true;
	bool status = false;
	if (p->left)
		status = searchHelper(p->left, key);
	if (!status && p->right)
	{
		status = searchHelper(p->right, key);
	}
	return status;
}
template <typename T>
void BST<T>::remove(T val)
{
	if (!root)
		return;
	if (root->info == val)
	{
		if (!root->left && !root->right)
			root = nullptr;
		else if (!root->left)
			root = root->right;
		else if (!root->right)
			root = root->left;
		else
			root->info = removeDegree2Node(root);
		return;
	}
	removeElem(val);
}
template <typename T>
void BST<T>::removeElem(T key)
{
	if (!root->left && !root->right)
		return;
	BSTNode<T>* ptr = (key >= root->info ? root->right : root->left);
	BSTNode<T>* prev = root;
	while (ptr)
	{
		if (key == ptr->info)
		{
			if (!ptr->left && !ptr->right)
			{
				if (prev->left == ptr)
					prev->left = nullptr;
				else
					prev->right = nullptr;
				delete ptr;
			}
			else if (!ptr->right && ptr->left)
			{
				if (prev->left == ptr)
					prev->left = ptr->left;
				else
					prev->right = ptr->right;
				delete ptr;
			}
			else if (!ptr->left && ptr->right)
			{
				if (prev->left == ptr)
					prev->left = ptr->right;
				else
					prev->right = ptr->right;
				delete ptr;
			}
			else
				ptr->info = removeDegree2Node(ptr);
			return;
		}
		else if (key > ptr->info)
		{
			prev = ptr;
			ptr = ptr->right;
		}
		else
		{
			prev = ptr;
			ptr = ptr->left;
		}
	}
}
template <typename T>
T BST<T>::removeDegree2Node(BSTNode<T>* ptr)
{
	BSTNode<T>* prev = ptr;
	ptr = ptr->right;
	while (ptr->left)
	{
		prev = ptr;
		ptr = ptr->left;
	}
	if (prev->right == ptr)
		prev->right = ptr->right;
	else
		prev->left = ptr->right;
	T temp = ptr->info;
	delete ptr;
	return temp;
}
template <typename T>
int BST<T>::heightOfTree(BSTNode<T>* p)
{
	if (!p)
		return 0;
	if (!p->left && !p->right)
		return 1;
	int left = 0, right = 0;
	if (p->left)
		left = heightOfTree(p->left);
	if (p->right)
		right = heightOfTree(p->right);
	if (left > right)
		return 1 + left;
	else
		return 1 + right;
}
template <typename T>
bool BST<T>::isAVL(BSTNode<T>* p)
{
	/*if (!p->left && !p->right)
		return true;*/
	int bf = heightOfTree(p->left) - heightOfTree(p->right);
	if (bf > -2 && bf < 2)
	{
		bool status = true;
		if (p->left)
			status = isAVL(p->left);
		if (status && p->right)
			status = isAVL(p->right);
		return status;
	}
	else
		return false;
}
template <typename T>
bool BST<T>::checkAVL()
{
	if (!root)
		return false;
	return isAVL(root);
}






//template<typename T>
//void BST<T>::remove(const T& key)
//{
//	BSTNode<T>* p = getParent(root, key);
//	if (!p)
//		return;
//	cout << p->info;
//}
//template<typename T>
//BSTNode<T>* BST<T>::getParent(BSTNode<T>* p, const T& key)
//{
//	BSTNode<T>* status = nullptr;
//	if (root->info == key)
//		return status;
//	if (p->left->info == key|| p->right->info)
//		status = p;
//	if (!status && p->left && p->left->info > key)
//		status = getParent(p->left, key);
//	if (!status && p->right && p->info < key)
//		status = getParent(p->right, key);
//	return status;
//}