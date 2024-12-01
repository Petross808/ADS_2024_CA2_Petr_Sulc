#pragma once

template<class K, class V>
struct KVPair
{
private:
	K key;
	V value;

public:

	KVPair(K key, V value);
	KVPair(K key);
	KVPair();

	K getKey();
	V getValue();

	bool operator<(KVPair<K, V>& other);
	bool operator>(KVPair<K, V>& other);
	bool operator==(KVPair<K, V>& other);
};

template<class K, class V>
inline KVPair<K, V>::KVPair(K k, V v)
{
	key = k;
	value = v;
}

template<class K, class V>
inline KVPair<K, V>::KVPair(K k) : value()
{
	key = k;
}

template<class K, class V>
inline KVPair<K, V>::KVPair() : key(), value() { }

template<class K, class V>
inline K KVPair<K, V>::getKey()
{
	return key;
}

template<class K, class V>
inline V KVPair<K, V>::getValue()
{
	return value;
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
