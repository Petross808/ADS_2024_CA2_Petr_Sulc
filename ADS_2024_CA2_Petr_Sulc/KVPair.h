#pragma once
#include "ValueList.h"
#include <ostream>

template<class K, class V>
struct KVPair
{
private:
	K key;
	ValueList<V> values;

public:

	KVPair(K key, V value);
	KVPair(K key);
	KVPair();

	K getKey();
	ValueList<V> getValueList();

	bool operator<(KVPair<K, V>& other);
	bool operator>(KVPair<K, V>& other);
	bool operator==(KVPair<K, V>& other);
	KVPair<K, V>& operator=(KVPair<K, V>& other);

	friend std::ostream& operator<<(std::ostream& out, KVPair<K, V>& key)
	{
		out << "\nKey: " << key.getKey() << " [" << key.getValueList().getSize() << " values]";
		return out;
	};
};

template<class K, class V>
inline KVPair<K, V>::KVPair(K k, V v)
{
	key = k;
	values.add(v);
}

template<class K, class V>
inline KVPair<K, V>::KVPair(K k)
{
	key = k;
}

template<class K, class V>
inline KVPair<K, V>::KVPair() : key()
{
}

template<class K, class V>
inline K KVPair<K, V>::getKey()
{
	return key;
}

template<class K, class V>
inline ValueList<V> KVPair<K, V>::getValueList()
{
	return values;
}

template<class K, class V>
inline bool KVPair<K, V>::operator<(KVPair<K, V>& other)
{
	return key < other.key;
}

template<class K, class V>
inline bool KVPair<K, V>::operator>(KVPair<K, V>& other)
{
	return key > other.key;
}

template<class K, class V>
inline bool KVPair<K, V>::operator==(KVPair<K, V>& other)
{
	return key == other.key;
}


template<class K, class V>
inline KVPair<K, V>& KVPair<K, V>::operator=(KVPair<K, V>& other)
{
	key = other.getKey();
	auto otherVals = other.getValueList();
	values.add(otherVals);
	return *this;
}
