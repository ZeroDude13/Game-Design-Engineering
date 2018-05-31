// date.h (textbook 11.12)
// Date class definition with overloaded increment operators.
#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
   friend ostream &operator<<( ostream &, const Date & );
public:
   Date( int m = 1, int d = 1, int y = 1900 ); // default constructor
   Date(const char*);
   void setDate( int, int, int );	// set month, day, year
   Date &operator++();				// prefix increment operator
   Date operator++( int );			// postfix increment operator
   const Date &operator+=( int );	// add days, modify object
   bool leapYear( int ) const;		// is date in a leap year?
   bool endOfMonth( int ) const;	// is date at the end of month?
   int operator-(const Date&) const;
   Date operator+ (int);
private:
   int month;
   int day;
   int year;

   static const int days[]; // array of days per month
   void helpIncrement(); // utility function for incrementing date
};

#endif