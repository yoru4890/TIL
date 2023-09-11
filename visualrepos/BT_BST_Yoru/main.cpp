#include <iostream>
#include "BST.h"

int main()
{
	mytree::BinarySearchTree<int> myBST;

	auto pRoot = myBST.GetRoot();

	pRoot->mData = 5;
	myBST.Insert(pRoot, 3);
	myBST.Insert(pRoot, 1);
	myBST.Insert(pRoot, 2);
	myBST.Insert(pRoot, 9);
	myBST.Insert(pRoot, 10);
	myBST.Insert(pRoot, 4);
	myBST.Insert(pRoot, 8);
	myBST.Insert(pRoot, 0);
	myBST.InOrderPrint(pRoot);
	std::cout << std::endl;
	myBST.Erase(pRoot, 3);
	myBST.InOrderPrint(pRoot);
	
}