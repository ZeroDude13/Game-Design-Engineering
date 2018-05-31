#include "Student.h"
#include "Person.h"
#include "Date.h"
#include <iostream>
using namespace std;

Student::Student(string name, int id, int age, string ssn) : Person(name, age, ssn) 
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

void Student::addCourse(string name, const char* start, const char* end)
{
	Course* course = new Course(name, start, end);
	coursesTaken[numCourses++] = course;
}

Course* Student::getCourse(string name)
{
	for (int i = 0; i < numCourses; i++){
		if (coursesTaken[i]->getName() == name)
			return coursesTaken[i];
	}

	return 0;
}

bool Student::isTakenCourse(string name, Date&)
{
	for (int i = 0; i < numCourses; i++){
		if (coursesTaken[i]->getName() == name &&
			coursesTaken[i]->getEndDate() <= date &&
			coursesTaken[i]->getLetterGrade() <= 'C')
			return true;
	}

	return false;
}

bool Student::isTakingCourse(string name)
{
	for (int i = 0; i < numCourses; i++){
		if (coursesTaken[i]->getName() == name)
			return true;
	}

	return false;
}

void Student::updateOverallGPA(Date& date)
{
	studentGPA = 0;
	int count = 0;
	for (int i = 0; i < numCourses; i++){
		if (coursesTaken[i]->getEndDate() <= date){
			count++;
			char grade = coursesTaken[i]->getLetterGrade();
			switch (grade)
			{
				case 'A':
					studentGPA += 4;
					break;
				case 'B':
					studentGPA += 3;
					break;
				case 'C':
					studentGPA += 2;
					break;
				case 'D':
					studentGPA += 1;
					break;
				case 'F':
					studentGPA += 0;
					break;
			}
			
		}
	}
	studentGPA /= count;
}

ostream& operator<<(ostream& out, const Student& student)
{
	out << (Person) student;
	cout << " - Student ID: " << student.studentID
		<< " - GPA: " << student.studentGPA
		<< " - Start: " << student.startDate;

	return out;
}

Student::~Student()
{

}