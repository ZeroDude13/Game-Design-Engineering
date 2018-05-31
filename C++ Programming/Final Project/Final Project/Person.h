#ifndef PERSON_H
#define PERSON_H
#include <string> 

class Person
{
	std::string personName;
	int personAge;
	//const string personId;
	std::string personId;
public:
	Person(std::string name, int age, std::string id);
	
	// accessors - functions that do not change data members
	std::string getName() { return personName; }
	int getAge() { return personAge; }
	std::string getId() { return personId; }
	std::string getId() const { return personId; }
	void storeToDisk();
	// mutators - functions that will change data members
	void setName(std::string name) { personName = name; }
	void setAge(int age) { personAge = age; }
	void setID(std::string id) { personId = id; }
	friend std::ostream &operator<<(std::ostream&, const Person&);
};

#endif