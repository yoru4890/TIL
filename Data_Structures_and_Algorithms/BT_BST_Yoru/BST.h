#pragma once
#include "BT.h"

namespace mytree
{
	template<typename T>
	class BinarySearchTree : public BinaryTree<T>
	{
	private:
		std::unique_ptr<Node<T>> mpRoot;

	public:
		BinarySearchTree() : mpRoot{ std::make_unique<Node<T>>(0)} {}

		Node<T>* Insert(Node<T>* parent, T data)
		{
			if (parent->mData > data)
			{
				if (!parent->mpLeft)
				{
					return this->InsertLeft(parent, data);
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
					return this->InsertRight(parent, data);
				}
				else
				{
					Insert(parent->mpRight.get(), data);
				}
			}
		}

		Node<T>* Find(Node<T>* node, T data)
		{
			if (!node) { return nullptr; }
			if (node->mData == data) { return node; }

			return node->mData > data ? Find(node->mpLeft.get(), data) : Find(node->mpRight.get(), data);
		}

		void Erase(Node<T>* node, T data)
		{
			Node<T>* p = node;
			Node<T>* pPre = node;

			while (p->mData != data)
			{
				pPre = p;
				if (p->mData > data) { p = p->mpLeft.get(); }
				else if (p->mData < data) { p = p->mpRight.get(); }
			}

			if (p)
			{
				Node<T>* pTemp{ p->mpLeft.get()};
				if (!pTemp)
				{
					if (pPre->mData < p->mData)
					{
						pPre->mpRight = std::move(p->mpRight);
					}
					else
					{
						pPre->mpLeft = std::move(p->mpRight);
					}
				}
				else
				{
					pPre = p;
					while (pTemp->mpLeft || pTemp->mpRight)
					{
						while (pTemp->mpRight) 
						{ 
							pPre = pTemp; 
							pTemp = pTemp->mpRight.get();
						}
						if (pTemp->mpLeft) 
						{ 
							pPre = pTemp;
							pTemp = pTemp->mpLeft.get(); 
						}
					}

					T tempData{ pTemp->mData };

					if (pPre->mData > pTemp->mData)
					{
						pPre->mpLeft.reset();
					}
					else
					{
						pPre->mpRight.reset();
					}

					p->mData = tempData;

				}

			}
			
		}
	};
}