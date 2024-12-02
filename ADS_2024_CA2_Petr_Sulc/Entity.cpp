#include "Entity.h"
#include <ostream>

Entity::Entity() : id(), firstName(), lastName(), age(), email(), score(), passed() { }

bool Entity::operator==(Entity& other)
{
	return id == other.id;
}

std::ostream& operator<<(std::ostream& out, Entity& key)
{
	 out << "{" << 
		key.id << ", " << 
		key.firstName << ", "<< 
		key.lastName << ", " << 
		key.age << ", " << 
		key.email << ", " << 
		key.score << ", " << 
		key.passed << "}\n";

	return out;
}
