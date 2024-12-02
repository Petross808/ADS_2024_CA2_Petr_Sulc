#pragma once
#include <ostream>

struct EntityKeyBase
{
public:
	void* key = nullptr;
	virtual bool operator<(const EntityKeyBase& other) const = 0;
	virtual bool operator>(const EntityKeyBase& other) const = 0;
	virtual bool operator==(const EntityKeyBase& other) const = 0;
	friend std::ostream& operator<<(std::ostream& out, const EntityKeyBase& key);
	virtual std::string getOutputString() const = 0;
};


inline std::ostream& operator<<(std::ostream& out, const EntityKeyBase& key)
{
	out << key.getOutputString();
	return out;
}