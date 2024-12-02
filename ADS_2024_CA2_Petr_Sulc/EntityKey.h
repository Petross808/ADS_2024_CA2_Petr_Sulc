#pragma once
#include "EntityKeyBase.h"
#include <sstream>

template<class T>
struct EntityKey : public EntityKeyBase
{
	EntityKey(T value);
	~EntityKey();

	bool operator<(const EntityKeyBase& other) const override;
	bool operator>(const EntityKeyBase& other) const override;
	bool operator==(const EntityKeyBase& other) const override;

	std::string getOutputString() const override;
};

template<class T>
inline EntityKey<T>::EntityKey(T value)
{
	key = new T(value);
}

template<class T>
inline EntityKey<T>::~EntityKey()
{
	if (key != nullptr)
	{
		delete key;
		key = nullptr;
	}
}


template<class T>
inline bool EntityKey<T>::operator<(const EntityKeyBase& other) const
{
	return *(T*)key < *(T*)other.key;
}

template<class T>
inline bool EntityKey<T>::operator>(const EntityKeyBase& other) const
{
	return *(T*)key > *(T*)other.key;
}

template<class T>
inline bool EntityKey<T>::operator==(const EntityKeyBase& other) const
{
	return *(T*)key == *(T*)other.key;
}


template<class T>
inline std::string EntityKey<T>::getOutputString() const
{
	T keyVal = *(T*)key;
	stringstream out;
	out << keyVal;
	return out.str();
}
