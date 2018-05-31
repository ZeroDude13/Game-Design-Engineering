#include <iostream>
#include <fstream>
#include "Person.h"
using namespace std;

Person::Person(string name, int age, const string iD) 
{
	personName = name;
	personAge = age;
	personId = iD;
}

void Person::setName(string name)
{
	personName = name;
}

void Person::setAge(int age)
{
	personAge = age;
}

void Person::setID(const string iD)
{
	personId = iD;
}

void Person::storeToDisk()
{
	Person data;
  fstream file;
  file.open("Person", ios::out | ios::trunc);
  for(unsigned long i=0; i < size;i++){
    file << msg[i];
  }
  file.close();
}

Person::~Person()
{

}

Person::Person(string name, int age, string id) : personId(id)
{
	personName = name;
	personAge = age;
}

ostream &operator<<(ostream &out, const Person &person)
{
	out << " Name: " << person.personName << " - SSN: " << person.personId 
		<< " - Age: " << person.personAge;

	return out;
}