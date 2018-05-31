#ifndef GRADTUTOR_H_
#define GRADTUTOR_H_
#include <iostream>
#include "Tutor.h"
#include
using namespace std;

class Tutor;

class GradTutor : public Student, public Tutor
{
public:
	GradTutor(string name, int id, int a, string ssn, int tutorID);
	friend ostream& operator<<( ostream &, const Tutor & );
	string addTutoringCourse();
	string isTutoringCourse();
	~GradTutor();
};

#endif