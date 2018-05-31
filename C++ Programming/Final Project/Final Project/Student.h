#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include "Date.h"
#include "Person.h"
#include "Course.h"

//class Person;
//class Course;
//class Date;

class Student : public Person
{
	const int TOTAL_NUM_COURSES = 30;
	int studentID;
	double studentGPA;
	Date startDate;
	Course* coursesTaken[TOTAL_NUM_COURSES];
	int numCourses;
public:
	Student(string name, int id, int age, string ssn);
	void addCourse(string, const char*, const char*);
	Course* getCourse(int idx) { return (idx <= numCourses ? coursesTaken[idx-1] : 0); }
	Course* getCourse(string);
	bool isTakenCourse(string, Date&);
	bool isTakingCourse(string);
	double getOverallGPA(){return studentGPA;}
	void updateOverallGPA(Date& date);
	void setStartDate(const char* date) { startDate = Date(date); }
	friend ostream& operator<<(ostream&, const Student&);
	~Student();
};

#endif