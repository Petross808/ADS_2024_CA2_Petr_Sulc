#pragma once
#include "BSTNode.h"
#include <vector>

template <class T>
class BinaryTree
{
private:
	void addItemToArray(BSTNode<T>* node, int& pos, T* arr);

public:
	BSTNode<T>* root;

	BinaryTree();
	BinaryTree(const BinaryTree<T>& other);

	BinaryTree<T>& operator=(const BinaryTree<T>& other);

	void add(T& item);
	bool remove(T& item);
	void clear();
	int count();
	bool get(T& const item, T& out);

	void printInOrder(std::ostream& os);
	void printInOrder(BSTNode<T>* node, std::ostream& os);
	void printPreOrder(std::ostream& os);
	void printPreOrder(BSTNode<T>* node, std::ostream& os);
	void printPostOrder(std::ostream& os);
	void printPostOrder(BSTNode<T>* node, std::ostream& os);

	T* toArray();

	~BinaryTree();
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other)
{
	root = nullptr;
	if (other.root != nullptr)
		root = new BSTNode<T>(*other.root);
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other)
{
	if (this == &other)
		return *this;

	root = nullptr;
	if (other.root != nullptr)
		root = new BSTNode<T>(*other.root);

	return *this;
}

template <class T>
void BinaryTree<T>::add(T& item)
{
	if (root == nullptr)
	{
		root = new BSTNode<T>(item, nullptr);
	}
	else
	{
		root->add(item);
	}
}

template <class T>
int BinaryTree<T>::count()
{
	if (root == nullptr)
		return 0;
	return root->count();
}

template <class T>
bool BinaryTree<T>::remove(T& item)
{
	BSTNode<T>* toBeRemoved = root;
	BSTNode<T>* parent = nullptr;
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{

		if (toBeRemoved->getItem() == item)
		{

			found = true;
		}
		else
		{
			parent = toBeRemoved;
			if (toBeRemoved->getItem() > item)
			{
				toBeRemoved = toBeRemoved->getLeft();
			}
			else
			{
				toBeRemoved = toBeRemoved->getRight();
			}
		}
	}
	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		BSTNode<T>* newChild;
		if (toBeRemoved->getLeft() == nullptr)
		{
			newChild = toBeRemoved->getRight();
		}
		else
		{
			newChild = toBeRemoved->getLeft();
		}
		if (parent == nullptr)
		{
			root = newChild;
		}
		else if (parent->getLeft() == toBeRemoved)
		{
			parent->setLeft(newChild);
		}
		else
		{
			parent->setRight(newChild);
		}
		return true;
	}

	BSTNode<T>* smallestParent = toBeRemoved;
	BSTNode<T>* smallest = toBeRemoved->getRight();
	while (smallest->getLeft() != nullptr)
	{
		smallestParent = smallest;
		smallest = smallest->getLeft();
	}
	toBeRemoved->setItem(smallest->getItem());
	if (smallestParent == toBeRemoved)
	{
		smallestParent->setRight(smallest->getRight());
	}
	else
	{
		smallestParent->setLeft(smallest->getRight());
	}

}

template <class T>
bool BinaryTree<T>::get(T& const item, T& out)
{
	bool found;
	BSTNode<T>* current = root;
	while (true)
	{
		if (current == nullptr)
		{
			found = false;
			break;
		}

		if (current->getItem() == item)
		{
			out = current->getItem();
			found = true;
			break;
		}

		if (current->getItem() > item)
			current = current->getLeft();
		else
			current = current->getRight();
	}

	return found;
}

template <class T>
void BinaryTree<T>::addItemToArray(BSTNode<T>* node, int& pos, T* arr)
{
	if (node != nullptr)
	{
		addItemToArray(node->getLeft(), pos, arr);
		arr[pos] = node->getItem();
		pos++;
		addItemToArray(node->getRight(), pos, arr);
	}

}

template <class T>
T* BinaryTree<T>::toArray()
{
	T* arr = new T[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}

template <class T>
void BinaryTree<T>::clear()
{
	delete root;
	root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
	if (root != nullptr)
	{
		delete root;
		root = nullptr;
	}
}

template<class T>
void BinaryTree<T>::printInOrder(std::ostream& os)
{
	this->printInOrder(root, os);
	os << '\n';
}

template<class T>
void BinaryTree<T>::printInOrder(BSTNode<T>* node, std::ostream& os)
{
	if (node == nullptr)
		return;

	printInOrder(node->getLeft(), os);	
	os << node->getItem() << ' ';
	printInOrder(node->getRight(), os);
}

template<class T>
void BinaryTree<T>::printPreOrder(std::ostream& os)
{
	this->printPreOrder(root, os);
	os << '\n';
}

template<class T>
void BinaryTree<T>::printPreOrder(BSTNode<T>* node, std::ostream& os)
{
	if (node == nullptr)
		return;

	os << node->getItem() << ' ';
	printPreOrder(node->getLeft(), os);
	printPreOrder(node->getRight(), os);
}

template<class T>
void BinaryTree<T>::printPostOrder(std::ostream& os)
{
	this->printPostOrder(root, os);
	os << '\n';
}

template<class T>
void BinaryTree<T>::printPostOrder(BSTNode<T>* node, std::ostream& os)
{
	if (node == nullptr)
		return;

	printPostOrder(node->getLeft(), os);
	printPostOrder(node->getRight(), os);
	os << node->getItem() << ' ';
}