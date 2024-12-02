#pragma once
#include "ValueNode.h"

template <class V>
struct ValueList
{
private:
	int size;
	ValueNode<V>* head;

public:
	ValueList();
	void add(V value);
	void add(ValueList<V>& list);
	ValueNode<V>* first();
	int getSize();

	void print();
};

template<class V>
inline ValueList<V>::ValueList()
{
	head = nullptr;
	size = 0;
}

template<class V>
inline void ValueList<V>::add(V value)
{
	if (head == nullptr)
	{
		head = new ValueNode<V>(value);
		size++;
		return;
	}

	ValueNode<V>* current = head;
	while (true)
	{
		if (current->value == value)
			break;

		if (current->next == nullptr)
		{
			current->next = new ValueNode<V>(value);
			size++;
			return;
		}

		current = current->next;
	}
}

template<class V>
inline void ValueList<V>::add(ValueList<V>& list)
{
	if (list.first() == nullptr)
		return;

	ValueNode<V>* current = list.first();
	for (int i = 0; i < list.getSize(); i++)
	{
		add(current->value);
		current = current->next;
	}
}

template<class V>
inline ValueNode<V>* ValueList<V>::first()
{
	return head;
}

template<class V>
inline int ValueList<V>::getSize()
{
	return size;
}

template<class V>
inline void ValueList<V>::print()
{
	if (first() == nullptr)
		return;

	ValueNode<V>* current = first();
	for (int i = 0; i < getSize(); i++)
	{
		cout << "\nValue [" << i << "]: " << current->value;
		current = current->next;
	}
}
