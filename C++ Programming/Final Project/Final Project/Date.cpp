// date.cpp (textbook fig. 11.13)
// Date class member- and friend-function definitions.
#include <iostream>
#include "Date.h"
#include <ctime>
using namespace std;

// initialize static member at file scope; one classwide copy
const int Date::days[] = 
   { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Date constructor
Date::Date( int m, int d, int y ) 
{ 
   setDate( m, d, y ); 
}

// conversion constructor
Date::Date(const char* instr)
{
	char str[20];
	strcpy(str, instr);

	char *remainstr = strtok(str, "/");	
	month = atoi(remainstr);			// read the first token & set the month

	remainstr = strtok(NULL, "/");
	day = atoi(remainstr);				// set day

	remainstr = strtok(NULL, "/");
	year = atoi(remainstr);				// set year
}
// set month, day and year
void Date::setDate( int mm, int dd, int yy )
{
   month = ( mm >= 1 && mm <= 12 ) ? mm : 1;
   year = ( yy >= 1900 && yy <= 2100 ) ? yy : 1900;

   // test for a leap year
   if ( month == 2 && leapYear( year ) )
      day = ( dd >= 1 && dd <= 29 ) ? dd : 1;
   else
      day = ( dd >= 1 && dd <= days[ month ] ) ? dd : 1;
}

// overloaded prefix increment operator 
Date &Date::operator++()
{
   helpIncrement(); // increment date
   return *this; // reference return to create an lvalue
}

// overloaded prefix increment operator 
Date Date::operator++(int)
{
	Date temp = *this;
   helpIncrement(); // increment date
   return temp; // reference return to create an lvalue
}


// add specified number of days to date
const Date &Date::operator+=( int additionalDays )
{
   for ( int i = 0; i < additionalDays; i++ )
      helpIncrement();

   return *this; // enables cascading
}

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear( int testYear ) const
{
   if ( testYear % 400 == 0 || 
      ( testYear % 100 != 0 && testYear % 4 == 0 ) )
      return true; // a leap year
   else
      return false; // not a leap year
}

// determine whether the day is the last day of the month
bool Date::endOfMonth( int testDay ) const
{
   if ( month == 2 && leapYear( year ) )
      return testDay == 29; // last day of Feb. in leap year
   else
      return testDay == days[ month ];
} // end function endOfMonth

// function to help increment the date
void Date::helpIncrement()
{
   // day is not end of month
   if ( !endOfMonth( day ) )
      day++; // increment day
   else 
      if ( month < 12 ) // day is end of month and month < 12
      {
         month++; // increment month
         day = 1; // first day of new month
      } // end if
      else // last day of year
      {
         year++; // increment year
         month = 1; // first month of new year
         day = 1; // first day of new month
      } // end else
}

// overloaded output operator
ostream &operator<<( ostream &output, const Date &d )
{
   static char *monthName[ 13 ] = { "", "January", "February",
      "March", "April", "May", "June", "July", "August",
      "September", "October", "November", "December" };
   output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;
   return output; // enables cascading
} 

// invoked when: Date d3 = d1 + 2;
//               Date d4;
//                    d4 = d1 + 2;
Date Date::operator+ (int days)
{
	// first make a copy of the current object - temp object
	Date temp = *this;
	// see how the overloaded operator+= implementation
	// on the temp object
	temp += days;
	// return the new object
	return temp;
}

int Date::operator-(const Date& date1) const
{
	struct tm tm1, tm2, tm3;
	// first, use struct tm to create a structure 
	// with the current's date
	tm1.tm_year = year - 1900;
	tm1.tm_mon = month;
	tm1.tm_mday = day;
	tm1.tm_hour = 0;
	tm1.tm_min = 0;
	tm1.tm_sec = 0;
	
	// 2nd, use struct tm to create another structure 
	// with the input date object(date1) 
	tm2.tm_year = date1.year - 1900;
	tm2.tm_mon = date1.month;
	tm2.tm_mday = date1.day;
	tm2.tm_hour = 0;
	tm2.tm_min = 0;
	tm2.tm_sec = 0;

	// use function difftime for the difference between 
	// the 2 tm structures
	double seconds = difftime(mktime(&tm1), mktime(&tm2));
	
	// Figure out how many days from the number of seconds
	int days = seconds /(60*60*24);

	// return the days
	return days;
}

/**************************************************************************
 * (C) Copyright 1992-2009 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/