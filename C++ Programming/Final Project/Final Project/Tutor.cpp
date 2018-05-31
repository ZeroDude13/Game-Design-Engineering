#include <iostream>
#include "Tutor.h"
using namespace std;

Tutor::Tutor(string name, int id, int age, string ssn) : Person(name, age, ssn) 
{
	setName(name);
	tutorID = id;
	setID(ssn);
	tutorCourses;
}

ostream& operator<<( ostream & out, const Tutor & tutor)
{
	out << (Person) tutor;
	out << " Tutor's ID: " << tutor.tutorId
		<< " - Tutoring courses: ";
	int size = tutor.tutorCourses.size();
	for (int i = 0; i < size; i++){
		if (i > 0)
			out << ", ";
		out << tutor.tutorCourses[i];
	out << '.';
	return out;
}

string Tutor::addTutoringCourse(string name)
{
	if (!isTutoringCourse(name))
		tutorCourses.push_back(name);
}
bool Tutor::isTutoringCourse(string name)
{
	vector<string>::iterator ptr;
	ptr = find (tutorCourses.begin(), tutorCourses.end(), name);
	if (ptr != tutorCourses.end())
		return true;
	return false;
}

Tutor::~Tutor()
{

}