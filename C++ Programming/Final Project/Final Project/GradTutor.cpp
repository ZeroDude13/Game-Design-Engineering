#include "GradTutor.h"
#include "Tutor.h"
#include <iostream>
using namespace std;

GradTutor::GradTutor(string name, int id, int a, string ssn, int tutorID)
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


string GradTutor::addTutoringCourse(string name)
{
	if (!isTutoringCourse(name))
		tutorCourses.push_back(name);
}

string GradTutor::isTutoringCourse(string name)
{
	vector<string>::iterator ptr;
	ptr = find (tutorCourses.begin(), tutorCourses.end(), name);
	if (ptr != tutorCourses.end())
		return true;
	return false;
}

GradTutor::~GradTutor()
{

}