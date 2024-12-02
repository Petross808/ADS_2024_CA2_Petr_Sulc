#include "ApplicationPart4.h"
#include "fstream"
#include <string>
#include <sstream>

void ApplicationPart4::AddEntityToMap(Entity& e)
{
    EntityKeyWrapper wrapper{};

    switch (selectedIndex)
    {
    case Entity::ID:
        wrapper.entityKey = new EntityKey<int>(e.id);
        break;
    case Entity::FIRST_NAME:
        wrapper.entityKey = new EntityKey<string>(e.firstName);
        break;
    case Entity::LAST_NAME:
        wrapper.entityKey = new EntityKey<string>(e.lastName);
        break;
    case Entity::AGE:
        wrapper.entityKey = new EntityKey<int>(e.age);
        break;
    case Entity::EMAIL:
        wrapper.entityKey = new EntityKey<string>(e.email);
        break;
    case Entity::SCORE:
        wrapper.entityKey = new EntityKey<float>(e.score);
        break;
    case Entity::PASSED:
        wrapper.entityKey = new EntityKey<bool>(e.passed);
        break;
    default:
        wrapper.entityKey = new EntityKey<int>(e.id);
        break;
    }

    map.put(wrapper, e);
}

void ApplicationPart4::LoadFile(const string& filePath, Entity::Fields index)
{
    map.clear();
    selectedIndex = index;
    ifstream in(filePath);
    string fileString;
    string titles;
    while (!in.eof())
    {
        if (titles == "")
        {
            getline(in, titles);
        }

        string line;
        getline(in, line);

        stringstream splitter(line);
        string idString, firstName, lastName, ageString, email, scoreString, passedString;

        getline(splitter, idString, ',');
        getline(splitter, firstName, ',');
        getline(splitter, lastName, ',');
        getline(splitter, ageString, ',');
        getline(splitter, email, ',');
        getline(splitter, scoreString, ',');
        getline(splitter, passedString, ',');

        Entity e;
        e.id = stoi(idString);
        e.firstName = firstName;
        e.lastName = lastName;
        e.age = stoi(ageString);
        e.email = email;
        e.score = stof(scoreString);
        e.passed = passedString == "true";

        AddEntityToMap(e);
    }
    in.close();
}

void ApplicationPart4::PrintKeys()
{
    map.printInOrder(cout);
}

void ApplicationPart4::PrintValues(const string& key)
{
    ValueList<Entity> list;
    stringstream sstream(key);
    EntityKeyWrapper wrapper{};

    switch (selectedIndex)
    {
    case Entity::ID:
    case Entity::AGE:
        int intKey;
        if (sstream >> intKey)
            wrapper.entityKey = new EntityKey<int>(intKey);
        break;
    case Entity::FIRST_NAME:
    case Entity::LAST_NAME:
    case Entity::EMAIL:
        wrapper.entityKey = new EntityKey<string>(key);
        break;
    case Entity::SCORE:
        float floatKey;
        if (sstream >> floatKey)
            wrapper.entityKey = new EntityKey<float>(floatKey);
        break;
    case Entity::PASSED:
        if (key == "0" || key == "1")
            wrapper.entityKey = new EntityKey<bool>(key == "1");
        break;
    default:
        break;
    }

    if (wrapper.entityKey == nullptr)
    {
        cout << "Invalid key\n";
        return;
    }

    list = map.get(wrapper);
    list.print();
}
