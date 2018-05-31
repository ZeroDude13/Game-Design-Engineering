#include "GradStudent.h"
#include "Student.h"
#include "Date.h"
#include <iostream>
using namespace std;

GradStudent::GradStudent(string name, int id, int a, string ssn) : Student(name, id, age, ssn)
{
	setName(name);
	studentID = id;
	studentGPA = 0;
	startDate = Date();
	setID(ssn);
	for ( int i = 0; i < TOTAL_NUM_COURSES; i++)
		coursesTaken[i] = 0;
	numCourses = 0;
}

void GradStudent::addCourse(string name, const char* start, const char* end)
{
	Course* course = new Course(name, start, end);
	coursesTaken[numCourses++] = course;
}

bool GradStudent::isTakenCourse(string name, Date&)
{
	for (int i = 0; i < numCourses; i++){
		if (coursesTaken[i]->getName() == name &&
			coursesTaken[i]->getEndDate() <= date &&
			coursesTaken[i]->getLetterGrade() <= 'C')
			return true;
	}

	return false;
}

bool GradStudent::isTakingCourse(string name)
{
	for (int i = 0; i < numCourses; i++){
		if (coursesTaken[i]->getName() == name)
			return true;
	}

	return false;
}

ostream& operator<<(ostream& out, const Student& student)
{
	out << (Person) student;
	cout << " - Student ID: " << student.studentID
		<< " - GPA: " << student.studentGPA
		<< " - Start: " << student.startDate;

	return out;
}

GradStudent::~GradStudent()
{

}