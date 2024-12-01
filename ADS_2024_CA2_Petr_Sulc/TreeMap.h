#pragma once
#include "BinaryTree.h"
#include "KVPair.h"

template <class K, class V>
class TreeMap
{
private:
	BinaryTree<KVPair<K, V>> binaryTree;

public:
	void put(K key, V value);

	bool containsKey(K key);
	V get(K key);

	bool removeKey(K key);
	void clear();

	int size();
	BinaryTree<K> keySet();
	V operator[](K key);
};

template<class K, class V>
inline void TreeMap<K, V>::put(K key, V value)
{
	KVPair<K, V> pair(key, value);
	binaryTree.add(pair);
}

template<class K, class V>
inline bool TreeMap<K, V>::containsKey(K key)
{
	return binaryTree.get(KVPair<K, V>(key)) != nullptr;
}

template<class K, class V>
inline V TreeMap<K, V>::get(K key)
{
	BSTNode<KVPair<K, V>>* found = binaryTree.get(KVPair<K, V>(key));

	if (found == nullptr)
		return V();

	return found->getItem().getValue();
}

template<class K, class V>
inline bool TreeMap<K, V>::removeKey(K key)
{
	return binaryTree.remove(KVPair<K, V>(key));
}

template<class K, class V>
inline void TreeMap<K, V>::clear()
{
	binaryTree.clear();
}

template<class K, class V>
inline int TreeMap<K, V>::size()
{
	return binaryTree.count();
}

template<class K, class V>
inline BinaryTree<K> TreeMap<K, V>::keySet()
{
	BinaryTree<K> keySet;
	KVPair<K, V>* pairArray = binaryTree.toArrayPreOrder();

	for (int i = 0; i < binaryTree.count(); i++)
	{
		K key = pairArray[i].getKey();
		keySet.add(key);
	}

	return keySet;
}

template<class K, class V>
inline V TreeMap<K, V>::operator[](K key)
{
	return get(key);
}