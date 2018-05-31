#ifndef _GRADEBOOK_H
#define _GRADEBOOK_H
#include <iostream>
#include "Person.h"

class GradeBook
{
private:
	GradeBook();
	Person** aSchool();
	int size();
	int currentSize();
	~GradeBook();
}

#endif