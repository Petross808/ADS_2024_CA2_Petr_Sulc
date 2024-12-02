#pragma once
#include "EntityKeyBase.h"

struct EntityKeyWrapper
{
	EntityKeyBase* entityKey;

	bool operator<(const EntityKeyWrapper& other) const;
	bool operator>(const EntityKeyWrapper& other) const;
	bool operator==(const EntityKeyWrapper& other) const;
	friend std::ostream& operator<<(std::ostream& out, const EntityKeyWrapper& key);
};

inline bool EntityKeyWrapper::operator<(const EntityKeyWrapper& other) const
{
	return *entityKey < *other.entityKey;
}

inline bool EntityKeyWrapper::operator>(const EntityKeyWrapper& other) const
{
	return *entityKey > *other.entityKey;
}

inline bool EntityKeyWrapper::operator==(const EntityKeyWrapper& other) const
{
	return *entityKey == *other.entityKey;
}

inline std::ostream& operator<<(std::ostream& out, const EntityKeyWrapper& key)
{
	out << *key.entityKey;
	return out;
}