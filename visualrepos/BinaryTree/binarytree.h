#pragma once
#include <iostream>

namespace mytree
{
	struct Node
	{
		int mData;
		std::unique_ptr<Node> mpLeft;
		std::unique_ptr<Node> mpRight;

		Node(int data = 0, std::unique_ptr<Node> pLeft = nullptr, std::unique_ptr<Node> pRight = nullptr) :
			mData{data} ,mpLeft{std::move(pLeft)}, mpRight{std::move(pRight)}
		{
		}
	};

	class BinaryTree
	{
	private:
		std::unique_ptr<Node> mpRoot;

	public:
		BinaryTree()
		{
			mpRoot = CreateNode(0);
		}

		std::unique_ptr<Node> CreateNode(int value, std::unique_ptr<Node> pLeft = nullptr, std::unique_ptr<Node> pRight = nullptr)
		{
			return std::make_unique<Node>( value, std::move(pLeft), std::move(pRight) );
		}

		Node* GetRoot() { return mpRoot.get(); }

		Node* InsertLeft(Node* parent, int value)
		{
			parent->mpLeft = CreateNode(value);
			return parent->mpLeft.get();
		}

		Node* InsertRight(Node* parent, int value)
		{
			parent->mpRight = CreateNode(value);
			return parent->mpRight.get();
		}
	};
}
