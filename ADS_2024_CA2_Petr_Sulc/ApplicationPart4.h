#pragma once
#include "TreeMap.h"
#include "Entity.h"
#include "EntityKey.h"
#include "EntityKeyBase.h"
#include "EntityKeyWrapper.h"

class ApplicationPart4
{
private:
	TreeMap<EntityKeyWrapper, Entity> map;
	Entity::Fields selectedIndex = Entity::ID;

	void AddEntityToMap(Entity& e);
public:
	void LoadFile(const string& filePath, Entity::Fields index);
	void PrintKeys();
	void PrintValues(const string& key);
};
