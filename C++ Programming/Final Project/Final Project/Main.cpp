#include "Date.h"
#include "Person.h"
#include "Course.h"
#include "Tutor.h"
#include "Student.h"
using namespace std;

int testDate();
int testPerson();
int testCourse();
int testStudent();
int testTutor();

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++){
		if (strcmp(argv[i], "date") > 0)
			testDate();
		if (strcmp(argv[i], "person") > 0)
			testPerson();

		if (strcmp(argv[i], "course") > 0)
			testCourse();

		if (strcmp(argv[i], "tutor") > 0)
			testTutor();

		if (strcmp(argv[i], "student") > 0)
			testStudent();
	}

	return 0;
}

int testStudent()
{
	int id = 101, age = 23;
	string ssn = "100111";

	cout << "\n\tUnit tests for class Student";

	cout << "\n\nTest Student constructor and overloaded operator<<:";
	Student *student1 = new Student("Student1 Last", id, age, ssn);
	student1->addCourse("Calculus III", "9/1/2013", "12/20/2013");

	if (student1->isTakenCourse("Calculus III"))
		student1->addCourse("SWE315", "9/1/2014", "12/20/2014");

	if (student1->isTakingCourse("SWE315"))
		cout << "\nYes, this student is taking the course";

	cout << "\nCurrent GPA: " << student1->getOverallGPA();

	// create a vector of students
	vector<Student> students;
	students.push_back(*student1);
	for (int i = 0; i < students.size(); i++)
		cout << "\n" << students.at(i);
}

int testTutor()
{
	int id = 1, age = 23;
	string ssn = "100111";

	cout << "\n\tUnit tests for class Tutor";

	cout << "\n\nTest Tutor constructor and overloaded operator<<:";
	Tutor object("Tutor1 Name", id, age, ssn);
	Tutor* tutor = &object;
	cout << tutor;

	tutor->addTutoringCourse("Calculus III");
	tutor->addTutoringCourse("SWE110");
	tutor->addTutoringCourse("SWE315");

	if (tutor->isTutoringCourse("SWE315"))
		cout << "\nYes, " << tutor->getName() << " is tutoring it";
	else
		cout << "\nNo, " << tutor->getName() << " is not tutoring it";
}

int testCourse()
{
	cout << "\n\tUnit tests for class Course";

	cout << "\n\nTest Course constructor and overloaded operator<<:";
	Course course("SWE315", "9/1/2014", "12/20/2014");
	cout << course;

	cout << "\nCourse name: " << course.getName();
	cout << "\nStart date: " << course.getStartDate();
	cout << "\nEnd date: " << course.getEndDate();
	cout << "\nCurrentGPA: " << course.getAverage();
	cout << "\nGrade: " << course.getLetterGrade();

	// add some test scores for the course
	for (int i = 0; i < course.getTotalNumTests()/2; i++)
		course.addTestScore(80);

	// test getTestScore
	for (int i = 0; i < course.getCurrentNumTest(); i++)
		cout << "\n\tTest " << i+1 << ": " << course.getTestScore(i);

	cout << "\nCurrentGPA: " << course.getAverage();
	cout << "\nGrade: " << course.getLetterGrade();
}

int testPerson()
{
	cout << "\n\tUnit tests for class Person";

	cout << "\n\nTest Person constructors and overloaded operator<<:";
	Person person1("person1 last", 20, "101");
	cout << person1;

	const Person person2("person2 last", 20, "102");
	cout << endl << person2;

	cout << "\n\nTest other member functions:";
	cout << "\nPerson1\'s id: " << person1.getId();
	cout << "\nPerson2\'s id: " << person2.getId();
	cout << "\nPerson1\'s name: " << person1.getName();
	cout << "\nPerson1\'s age: " << person1.getAge();
	
	return 0;
}

int testDate()
{
	cout << "\n\tUnit tests for class Date";

	// test both constructors
	cout << "\n\nTest Date constructors and overloaded operator<<:";
	Date d1;				// invoke the default constructor
	Date d2("11/10/2014");	// invoke the conversion constructor

	cout << endl << d1;
	cout << endl << d2;

	// test the overloaded operator+
	cout << "\n\nTest overloaded operator+:\n";
	Date d3 = d1 + 3;
	d3 = (d1 + 3) + 3;
	cout << d1 << endl;	// expect d1 values should not changed
	cout << d3;			// expect d3 = d1 + 9

	// test the overloaded operator+=
	cout << "\n\nTest overloaded operator+=:\n";
	d3 += 35;
	cout << d3;

	// test the overloaded operator++ prefix
	cout << "\n\nTest overloaded operator++ prefix:\n";
	++d3;
	cout << d1;

	// test the overloaded operator++ postfix
	cout << "\n\nTest overloaded operator++ postfix:\n";
	d3++;
	cout << d1;

	// test the overloaded operator-
	cout << "\n\nTest overloaded operator-:\n";
	d2 = d3 - d1;
	cout << d2 << endl;
	cout << d3 - d1;

	return 0;
}