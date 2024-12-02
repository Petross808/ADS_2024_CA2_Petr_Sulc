#pragma once
#include <string>

struct Entity
{
	enum Fields { ID, FIRST_NAME, LAST_NAME, AGE, EMAIL, SCORE, PASSED };

	int id;
	std::string firstName;
	std::string lastName;
	int age;
	std::string email;
	float score;
	bool passed;

	Entity();
	bool operator==(Entity& other);
	friend std::ostream& operator<<(std::ostream& out, Entity& key);
};