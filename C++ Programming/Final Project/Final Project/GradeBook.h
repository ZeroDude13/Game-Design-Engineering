#ifndef _GRADEBOOK_H
#define _GRADEBOOK_H
#include "Person.h"
#include <iostream>

class GradeBook
{
private:
	Person** aSchool();
	int size();
	int currentSize();
public:
	GradeBook();

	~GradeBook();
}

#endif