#include <iostream>
#include "Course.h"
#include "date.h"
using namespace std;

Course::Course(string name, const char* sDate, const char* eDate)
{
	courseName = name;
	startDate = Date(sDate);
	endDate = Date(eDate);
	courseGrade = 0;
	for (int i = 0; i < TOTAL_NUM_TEST; i++)
		courseWorks[i] = 0;
	numTests = 0;
}

ostream &operator<<( ostream & out, const Course & course)
{
	out << course.courseName 
		<< " - From: " << course.startDate << " - To: " << course.endDate
		<< " - Grade: " << course.courseGrade;
	return out;
}

void Course::addTestScore(int score)
{
	courseWorks[numTests] = score;
	numTests++;
	// go through the courses and compute the average
	double sum = 0;
	for (int i = 0; i < numTests; i++)
		sum += courseWorks[i];
	courseGrade = sum / numTests;
}

double Course::getAverage()
{
	return courseGrade;
}


int Course::isEnded()
{

}

Course::~Course()
{

}

// accessors
char Course::getLetterGrade()
{
	if (courseGrade >= 90)
		return 'A';
	else if (courseGrade >= 80)
		return 'B';
	else if (courseGrade >= 70)
		return 'C';
	else if (courseGrade >= 60)
		return 'D';
	else
		return 'F';
}
