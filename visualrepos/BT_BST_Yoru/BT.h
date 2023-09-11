#pragma once
#include <iostream>

namespace mytree
{
	template<typename T>
	struct Node
	{
		T mData{};

		std::unique_ptr<Node<T>> mpLeft{};
		std::unique_ptr<Node<T>> mpRight{};

		Node(T data, std::unique_ptr<Node<T>> left = nullptr, std::unique_ptr<Node<T>> right = nullptr)
			: mData(data), mpLeft(std::move(left)), mpRight(std::move(right)) {}
	};

	template<typename T>
	class BinaryTree
	{
	private:

		std::unique_ptr<Node<T>> mpRoot;
		
	public:

		BinaryTree() : mpRoot{ std::make_unique<Node<T>>(0) } {}

		std::unique_ptr<Node<T>> CreateNode(T data, std::unique_ptr<Node<T>> pLeft = nullptr, std::unique_ptr<Node<T>> pRight = nullptr)
		{
			return std::make_unique<Node<T>>(data, std::move(pLeft), std::move(pRight));
		}

		Node<T>* GetRoot() { return mpRoot.get(); }

		Node<T>* InsertLeft(Node<T>* parent, T data)
		{
			parent->mpLeft = CreateNode(data);
			return parent->mpLeft.get();
		}

		Node<T>* InsertRight(Node<T>* parent, T data)
		{
			parent->mpRight = CreateNode(data);
			return parent->mpRight.get();
		}

		void InOrderPrint(Node<T>* root)
		{
			if (!root) { return; }

			InOrderPrint(root->mpLeft.get());
			std::cout << root->mData << ' ';
			InOrderPrint(root->mpRight.get());
		}

	};
}

