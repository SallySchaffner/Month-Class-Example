// Implementation file for the Month class
#include <iostream>
#include "Month.h"
using namespace std;

//*************************************
// Default constructor                *
//*************************************

Month::Month()
{
    // Initialize the array of month names.
    initializeNames();

    // Set this object to January, the 1st month.
    setMonthName(months[0]);
}


//*************************************
// Overloaded constructor             *
//*************************************

Month::Month(string n)
{
    // Initialize the array of month names.
    initializeNames();

    // Set object to n
    setMonthName(n);
}

//*************************************
// Overloaded constructor             *
//*************************************

Month::Month(int num)
{
    // Initialize the array of month names.
    initializeNames();

    // Set index to num
    setMonthNumber(num);
}

//******************************************
// initializeNames private member function *
//******************************************

void Month::initializeNames()
{
    // Initialize the array of month names.
    months[0] = "January"; months[1] = "February";  months[2] = "March";
    months[3] = "April";   months[4] = "May";       months[5] = "June";
    months[6] = "July";    months[7] = "August";    months[8] = "September";
    months[9] = "October"; months[10] = "November"; months[11] = "December";
}

//******************************************
// setMonthName member function            *
//******************************************

void Month::setMonthName(string n)
{
    monthNumber = 0;

    for (int i = 0; i < 12; i++)
    {
        if (months[i] == n)
        {
            name = months[i];
            monthNumber = i + 1;
        }
    }

    if (monthNumber == 0)
    {
        cout << "ERROR: Invalid month.\n";
        name = "January";
        monthNumber = 1;
    }
}

//******************************************
// setMonthNumber member function          *
//******************************************

void Month::setMonthNumber(int num)
{
    if (num < 1 || num > 12)
    {
        cout << "ERROR: Invalid month number.\n";
        name = "January";
        monthNumber = 1;
    }
    else
    {
        name = months[num - 1];
        monthNumber = num;
    }
}

//******************************************
// Prefix ++ operator                      *
//******************************************

Month Month::operator ++()
{
    if (monthNumber == 12)
    {
        monthNumber = 1;
        name = "January";
    }
    else
    {
        monthNumber++;
        name = months[monthNumber - 1];
    }

    return *this;
}

//******************************************
// Postfix ++ operator                     *
//******************************************

Month Month::operator ++(int)
{
    Month temp(monthNumber);

    if (monthNumber == 12)
    {
        monthNumber = 1;
        name = "January";
    }
    else
    {
        monthNumber++;
        name = months[monthNumber - 1];
    }

    return temp;
}

//******************************************
// Prefix -- operator                      *
//******************************************

Month Month::operator --()
{
    if (monthNumber == 1)
    {
        monthNumber = 12;
        name = "December";
    }
    else
    {
        monthNumber--;
        name = months[monthNumber - 1];
    }

    return *this;
}

//******************************************
// Postfix -- operator                     *
//******************************************

Month Month::operator --(int)
{
    Month temp(monthNumber);

    if (monthNumber == 1)
    {
        monthNumber = 12;
        name = "December";
    }
    else
    {
        monthNumber--;
        name = months[monthNumber - 1];
    }

    return temp;
}

//*************************************************
// Overloaded stream insertion operator (<<).     *
//*************************************************

ostream& operator<<(ostream& strm, Month& obj)
{
    strm << obj.name;
    return strm;
}

//*************************************************
// Overloaded stream extraction operator (>>).    *
//*************************************************

istream& operator>>(istream& strm, Month& obj)
{
    // Validate user input
    strm >> obj.name;
    obj.setMonthName(obj.name);
    return strm;
}