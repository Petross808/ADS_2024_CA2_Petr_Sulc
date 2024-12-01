#pragma once

template<class V>
struct ValueNode
{
	ValueNode<V>* next;
	V value;

	ValueNode(V value);
	ValueNode(V v, ValueNode<V>* next);
	~ValueNode();
};

template<class V>
inline ValueNode<V>::ValueNode(V v)
{
	next = nullptr;
	value = v;
}

template<class V>
inline ValueNode<V>::ValueNode(V v, ValueNode<V>* n)
{
	next = n;
	value = v;
}

template<class V>
inline ValueNode<V>::~ValueNode()
{
	if(next != nullptr)
	{
		delete next;
		next = nullptr;
	}
}


