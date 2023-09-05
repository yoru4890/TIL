#include <iostream>
#include "binarytree.h"

int main()
{
	//		 1
	//	  2	    3
	//   4 5   6 7

	mytree::BinaryTree binaryTree;
	binaryTree.GetRoot()->mData = 1;
	binaryTree.InsertLeft(binaryTree.InsertLeft(binaryTree.GetRoot(), 2), 4);
	binaryTree.InsertRight(binaryTree.InsertLeft(binaryTree.GetRoot(), 2), 5);
	binaryTree.InsertLeft(binaryTree.InsertRight(binaryTree.GetRoot(), 3), 6);
	binaryTree.InsertRight(binaryTree.InsertRight(binaryTree.GetRoot(), 3), 7);
}