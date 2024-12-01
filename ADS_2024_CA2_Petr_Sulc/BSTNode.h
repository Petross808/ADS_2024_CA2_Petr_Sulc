#pragma once

using namespace std;
template <class T>
class BSTNode
{
private:
	BSTNode<T> *parent;
	BSTNode<T> *left;
	BSTNode<T> *right;
	T data;
	
public:
	BSTNode(); 
	BSTNode(const BSTNode<T>& other);
	BSTNode(T data, BSTNode<T> *parent);

	~BSTNode();

	BSTNode<T>& operator=(const BSTNode<T>& other);

	T& getItem();
	BSTNode<T>* getParent();
	BSTNode<T>* getLeft();
	BSTNode<T>* getRight();

	void setItem(T item);
	void setLeft(BSTNode<T> *l);
	void setRight(BSTNode<T> *r);

	int count();
	void add(T& item);
};

template <class T>
BSTNode<T>::BSTNode() : data()
{
	parent = left = right = nullptr;
}

template <class T>
BSTNode<T>::BSTNode(T data, BSTNode<T> *parent)
{
	left = nullptr;
	right = nullptr;
	this->data = data;
	this->parent = parent;
}

template <class T>
BSTNode<T>::BSTNode(const BSTNode<T>& other)
{
	data = other.data;
	parent = left = right = nullptr;
	if (other.left != nullptr)
	{
		this->left = new BSTNode<T>(*other.left);
		this->left->parent = this;
	}
	if (other.right != nullptr)
	{
		this->right = new BSTNode<T>(*other.right);
		this->right->parent = this;
	}
}

template <class T>
BSTNode<T>::~BSTNode()
{
	if (left != nullptr)
	{
		delete left;
		left = nullptr;
	}

	if(right != nullptr)
	{
		delete right;
		right = nullptr;
	}
}

template <class T>
T& BSTNode<T>::getItem()
{
	return this->data;
}

template <class T>
BSTNode<T>* BSTNode<T>::getLeft()
{
	return this->left;
}

template <class T>
BSTNode<T>* BSTNode<T>::getRight()
{
	return this->right;
}

template <class T>
BSTNode<T>* BSTNode<T>::getParent()
{
	return this->parent;
}

template <class T>
void BSTNode<T>::setItem(T item)
{
	this->data = item;
}

template <class T>
void BSTNode<T>::setLeft(BSTNode<T> *l)
{
	this->left = l;
	if(l != nullptr)
		this->left->parent = this;
}

template <class T>
void BSTNode<T>::setRight(BSTNode<T> *r)
{
	this->right = r;
	if (r != nullptr)
		this->right->parent = this;
}

template <class T>
BSTNode<T>& BSTNode<T>::operator=(const BSTNode<T>& other)
{
	if (this == &other)
		return *this;

	data = other.data;
	parent = left = right = nullptr;
	if (other.left != nullptr)
	{
		this->setLeft(new BSTNode<T>(*other.left));
	}
	if (other.right != nullptr)
	{
		this->setRight(new BSTNode<T>(*other.right));
	}
	return *this;
}

template <class T>
int BSTNode<T>::count()
{
	int c = 1;
	if (left != nullptr)
	{
		c += left->count();
	}
	if (right != nullptr)
	{
		c += right->count();
	}
	return c;
}

template <class T>
void BSTNode<T>::add(T& item)
{
	if (item == this->data)
	{
		this->data = item;
		return;
	}

	if (item < this->data)
	{
		if (left == nullptr)
			left = new BSTNode<T>(item, this);
		else
			left->add(item);
	}
	else
	{
		if (right == nullptr)
			right = new BSTNode<T>(item, this);
		else
			right->add(item);
	}
}

