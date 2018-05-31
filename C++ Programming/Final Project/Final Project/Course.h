#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "date.h"
using namespace std;

class Course
{
	const int TOTAL_NUM_TEST = 6;	// there are 6 tests over the couse
	string courseName;
	double courseGrade;			// average of currently taken tests
	Date startDate;			// course start date
	Date endDate;				// course end date
	int courseWorks[TOTAL_NUM_TEST];
	int numTests;				// number of course work already completed

public:
	Course(string, const char*, const char*);	// will invoke Date's conversion constructor

	// accessors
	string getName() { return courseName; }
	Date getStartDate() { return startDate; }
	Date getEndDate() { return endDate; }
	double getAverage() { return courseGrade; }
	char getLetterGrade();
	int getTestScore(int idx) { return courseWorks[idx - 1]; }
	int getCurrentNumTest() { return numTests; }
	int getTotalNumTests() { return TOTAL_NUM_TEST; }

	// mutators
	void changeName(string name) { courseName = name; }
	void addTestScore(int score);

	// overloading operators
	friend ostream &operator<<(ostream&, const Course&);	
};

class Course
{
	static const int TOTAL_NUM_TEST = 6;		// there are 6 tests over the couse
	string courseName;
	double courseGrade;					// average of currently taken tests
	Date startDate;						// course start date
	Date endDate;						// course end date
	int courseWorks[TOTAL_NUM_TEST];
	int numTests;						// number of course work already completed

public:
	Course(std::string, const char*, const char*);		// will invoke Date's conversion constructor

	// accessors
	string getName() { return courseName; }
	Date getStartDate() { return startDate; }
	Date getEndDate() { return endDate; }
	double getAverage() { return courseGrade; }
	char getLetterGrade();
	int getTestScore(int idx) { return courseWorks[idx - 1]; }
	int getCurrentNumTest() { return numTests; }
	int getTotalNumTests() { return TOTAL_NUM_TEST; }

	// mutators
	void changeName(string name) { courseName = name; }
	void addTestScore(int);		// add a test score + update courseGrade

	// overloading operators
	friend ostream &operator<<(ostream&, const 


#endif