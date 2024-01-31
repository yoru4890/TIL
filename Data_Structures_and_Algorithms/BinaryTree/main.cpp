#include <iostream>
// include "binarytree.h"
//#include "bst.h"
//#include "quadtree.h"
#include "heap.h"
#include <queue>

int main()
{
	//BSTTest();
	//QTTest();
	//HeapTest();

	std::priority_queue<int> q;
	q.push(3);
	q.push(8);
	q.push(1);
	q.push(10);
	q.push(4);

	while (!q.empty())
	{
		std::cout << q.top() << std::endl;
		q.pop();
	}
}

