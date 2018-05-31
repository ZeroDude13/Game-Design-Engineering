#ifndef GRADSTUDENT_H_
#define GRADSTUDENT_H_
#include <iostream>
#include "Student.h"

//class Student;

class GradStudent : public Student
{
	Date gradDate;
	Course* gradCourses[10];

public:
	GradStudent(string name, int id, int a, string ssn);
	void addCourse(string, const char*, const char*);
	bool isTakenCourse(string);
	bool isTakingCourse(string);
	double getOverallGPA(){return getOverallGPA();}
	friend ostream& operator<<(ostream&, const Student&);
	~GradStudent();
};

#endif