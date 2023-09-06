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
			mData{ data }, mpLeft{ std::move(pLeft) }, mpRight{ std::move(pRight) }
		{
		}
	};

	class BinarySearchTree
	{
	private:
		std::unique_ptr<Node> mpRoot;

	public:
		BinarySearchTree()
		{
			mpRoot = CreateNode(0);
		}

		std::unique_ptr<Node> CreateNode(int value, std::unique_ptr<Node> pLeft = nullptr, std::unique_ptr<Node> pRight = nullptr)
		{
			return std::make_unique<Node>(value, std::move(pLeft), std::move(pRight));
		}

		Node* GetRoot() { return mpRoot.get(); }

		Node* Insert(Node* parent, int data)
		{
			if (parent->mData > data) 
			{ 
				if (!parent->mpLeft)
				{
					parent->mpLeft = CreateNode(data);
					return parent->mpLeft.get();
				}
				else
				{
					Insert(parent->mpLeft.get(), data);
				}
			}
			else if (parent->mData < data) 
			{ 
				if (!parent->mpRight)
				{
					parent->mpRight = CreateNode(data);
					return parent->mpRight.get();
				}
				else
				{
					Insert(parent->mpRight.get(), data);
				}
			}
		}

		void InOrder(Node* node)
		{
			if (!node)return;

			InOrder(node->mpLeft.get());
			std::cout << node->mData << ' ';
			InOrder(node->mpRight.get());
		}
	};
}