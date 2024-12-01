#pragma once
#include "BSTNode.h"
#include <vector>

template <class T>
class BinaryTree
{
private:
	void addItemToArray(BSTNode<T>* node, int& pos, T* arr);
	void addItemToArrayPreOrder(BSTNode<T>* node, int& pos, T* arr);

public:
	BSTNode<T>* root;

	BinaryTree();
	BinaryTree(const BinaryTree<T>& other);

	BinaryTree<T>& operator=(const BinaryTree<T>& other);

	void add(T& item);
	bool remove(T& item);
	void clear();
	int count();
	BSTNode<T>* get(T& item);

	void printInOrder(std::ostream& os);
	void printInOrder(BSTNode<T>* node, std::ostream& os);
	void printPreOrder(std::ostream& os);
	void printPreOrder(BSTNode<T>* node, std::ostream& os);
	void printPostOrder(std::ostream& os);
	void printPostOrder(BSTNode<T>* node, std::ostream& os);

	T* toArray();
	T* toArrayPreOrder();

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
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{
		if (toBeRemoved->getItem() == item)
		{
			found = true;
			break;
		}

		if (toBeRemoved->getItem() > item)
		{
			toBeRemoved = toBeRemoved->getLeft();
		}
		else
		{
			toBeRemoved = toBeRemoved->getRight();
		}
	}
	
	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		BSTNode<T>* child;
		if (toBeRemoved->getLeft() != nullptr)
		{
			child = toBeRemoved->getLeft();
		}
		else if (toBeRemoved->getRight() != nullptr)
		{
			child = toBeRemoved->getRight();
		}
		else
		{
			child = nullptr;
		}

		BSTNode<T>* parent = toBeRemoved->getParent();
		if (parent == nullptr)
		{
			root = child;
		}
		else if (parent->getLeft() == toBeRemoved)
		{
			parent->setLeft(child);
		}
		else
		{
			parent->setRight(child);
		}

		toBeRemoved->setLeft(nullptr);
		toBeRemoved->setRight(nullptr);
		delete toBeRemoved;
		return true;
	}

	BSTNode<T>* smallest = toBeRemoved->getRight();
	while (smallest->getLeft() != nullptr)
	{
		smallest = smallest->getLeft();
	}

	BSTNode<T>* smallestParent = smallest->getParent();
	toBeRemoved->setItem(smallest->getItem());

	if (smallestParent == toBeRemoved)
	{
		smallestParent->setRight(smallest->getRight());
	}
	else
	{
		smallestParent->setLeft(smallest->getRight());
	}

	smallest->setLeft(nullptr);
	smallest->setRight(nullptr);
	delete smallest;
	return true;
}

template <class T>
BSTNode<T>* BinaryTree<T>::get(T& item)
{
	BSTNode<T>* current = root;
	while (true)
	{
		if (current == nullptr)
		{
			return nullptr;
		}

		if (current->getItem() == item)
		{
			return current;
		}

		if (current->getItem() > item)
			current = current->getLeft();
		else
			current = current->getRight();
	}
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
void BinaryTree<T>::addItemToArrayPreOrder(BSTNode<T>* node, int& pos, T* arr)
{
	if (node != nullptr)
	{
		arr[pos] = node->getItem();
		pos++;
		addItemToArrayPreOrder(node->getLeft(), pos, arr);
		addItemToArrayPreOrder(node->getRight(), pos, arr);
	}
}

template <class T>
T* BinaryTree<T>::toArray()
{
	if (root == nullptr)
		return nullptr;

	T* arr = new T[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}

template <class T>
T* BinaryTree<T>::toArrayPreOrder()
{
	if (root == nullptr)
		return nullptr;

	T* arr = new T[root->count()];
	int pos = 0;
	addItemToArrayPreOrder(root, pos, arr);
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