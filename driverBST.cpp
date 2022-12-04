#include"BST.h"
#include<iostream>
using namespace std;
int main()
{
	BST<int> q;
	q.insert(5);
	q.insert(1);
	q.insert(2);
	q.insert(8);
	q.insert(0);
	q.insert(10);
	q.insert(11);
	q.insert(7);
	q.insert(6);

	cout << q.checkAVL();


	return 0;
}