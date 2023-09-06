#pragma once
#include <iostream>
#include <queue>
#include <stack>

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

	public:
		void Visit(Node* node) { std::cout << node->mData << ' '; }

		// time complexity : O(n)
		// space complexity : O(n)
		void BreadthFirstSearch()
		{
			std::queue<Node*> q;

			q.push(mpRoot.get());

			while (!q.empty())
			{
				auto node = q.front();
				Visit(node);
				q.pop();

				if (node->mpLeft)
				{
					q.push(node->mpLeft.get());
				}
				if (node->mpRight)
				{
					q.push(node->mpRight.get());
				}
			}
		}

		// time complexity : O(n)
		// space complexity : O(n)
		void DepthFirstSearch()
		{
			std::stack<Node*> s;

			s.push(mpRoot.get());

			while (!s.empty())
			{
				auto node = s.top();
				Visit(node);
				s.pop();

				if (node->mpRight) s.push(node->mpRight.get());
				if (node->mpLeft) s.push(node->mpLeft.get());

			}
		}

		// time complexity : O(n)
		// space complexity : O(n) ~ O(log n)
		void DFSRecursive(Node* node)
		{
			if (!node)return;

			Visit(node);

			DFSRecursive(node->mpLeft.get());
			DFSRecursive(node->mpRight.get());
		}

		void PreOrder(Node* node)
		{
			if (!node)return;

			Visit(node);

			PreOrder(node->mpLeft.get());
			PreOrder(node->mpRight.get());
		}

		void InOrder(Node* node)
		{
			if (!node)return;

			InOrder(node->mpLeft.get());
			Visit(node);
			InOrder(node->mpRight.get());
		}

		void PostOrder(Node* node)
		{
			if (!node)return;

			PostOrder(node->mpLeft.get());
			PostOrder(node->mpRight.get());
			Visit(node);
		}

		int Sum(Node* node)
		{
			if (!node) { return 0; }

			return Sum(node->mpLeft.get()) + node->mData + Sum(node->mpRight.get());
		}

		bool Search(Node* node, int value)
		{
			if (!node) { return false; }
			if (node->mData == value || Search(node->mpLeft.get(), value) || Search(node->mpRight.get(), value)) { return true; }

			return false;
		}

		int Depth(Node* node, int deep)
		{
			if (!node) { return deep; }
			
			return std::max(Depth(node->mpLeft.get(), deep + 1), Depth(node->mpRight.get(), deep + 1));
		}
	};
}
