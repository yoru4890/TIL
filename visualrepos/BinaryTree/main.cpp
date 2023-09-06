#include <iostream>
// include "binarytree.h"
#include "bst.h"

void BT_Test()
{
	////		 1
	////	  2	    3
	////   4 5   6 7

	//mytree::BinaryTree binaryTree;
	//auto pRoot = binaryTree.GetRoot();
	//pRoot->mData = 1;
	//mytree::Node* pNode{ binaryTree.InsertLeft(pRoot, 2) };
	//binaryTree.InsertLeft(pNode, 4);
	//pNode = binaryTree.InsertRight(pRoot, 3);
	//binaryTree.InsertLeft(pNode, 6);
	//binaryTree.InsertRight(pNode, 7);

	////PrintTree(pRoot);

	//binaryTree.BreadthFirstSearch();
	//std::cout << std::endl;

	//binaryTree.DepthFirstSearch();
	//std::cout << std::endl;

	//binaryTree.DFSRecursive(pRoot);
	//std::cout << std::endl;

	//std::cout << binaryTree.Sum(pRoot) << std::endl;
	//std::cout << binaryTree.Search(pRoot, 1) << std::endl;
	//std::cout << binaryTree.Search(pRoot, 0) << std::endl;
	//std::cout << binaryTree.Search(pRoot, 8) << std::endl;
	//std::cout << binaryTree.Search(pRoot, 7) << std::endl;

	//std::cout << binaryTree.Depth(pRoot, 0) << std::endl;
}

int main()
{
	mytree::BinarySearchTree bst;
	auto pRoot{ bst.GetRoot() };
	pRoot->mData = 5;
	bst.Insert(pRoot, 3);
	bst.Insert(pRoot, 10);
	bst.Insert(pRoot, 2);
	bst.Insert(pRoot, 9);
	bst.InOrder(pRoot);
	std::cout << std::endl;
}