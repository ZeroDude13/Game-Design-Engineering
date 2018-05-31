#ifndef _TUTOR_H_
#define _TUTOR_H_
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Course.h"
using namespace std;

class Person;
class Course;

class Tutor : public Person
{
	int tutorID;
	vector<string> tutorCourses;
public:
	Tutor(string name, int id, int age, string ssn);
	friend ostream& operator<<(ostream&, const Tutor&);
	string addTutoringCourse(string);
	bool isTutoringCourse(string);
	~Tutor();
};

#endif