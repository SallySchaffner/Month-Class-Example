// Chapter 14, Programming Challenge 7: Month Class
#include <iostream>
#include "Month.h"
using namespace std;

int main()
{
	cout << "Create a Month object from the default constructor\n";
	Month mDefault;
	cout << mDefault.getMonthName() << "   " << mDefault.getMonthNumber() << endl << endl;

	cout << "Create a Month object from the name constructor ((March)\n";
	Month mName("March");
	cout << mName.getMonthName() << "    " << mName.getMonthNumber() << endl << endl;
	cout << endl;

	cout << "Create a Month object from the number constructor (10)\n";
	Month mNum(10);
	cout << mNum.getMonthName() << "    " << mNum.getMonthNumber() << endl << endl;

	cout << "Test set name with bad input (OCT)\n";
	Month m;
	m.setMonthName("OCT");
	cout << m.getMonthName() << "    " << m.getMonthNumber() << endl << endl;

	cout << "Test set number with bad input (0)\n";
	m.setMonthNumber(0);
	cout << m.getMonthName() << "    " << m.getMonthNumber() << endl << endl;

	cout << "Test setters and getters with good inputs\n";
	m.setMonthName("July");
	cout << m.getMonthName() << endl;
	cout << m.getMonthNumber() << endl << endl;

	m.setMonthNumber(2);
	cout << m.getMonthName() << endl;
	cout << m.getMonthNumber() << endl << endl;;

	cout << "Test the prefix++ operator.\n";
	m.setMonthName("December");
	cout << "Before pre-increment: " << m.getMonthName() << endl;
	++m;
	cout << "After pre-increment: " << m << endl << endl;

	cout << "Test the postfix++ operator\n";
	cout << "Before post-increment: " << m << endl;
	m++;
	cout << "After post-increment: " << m << endl << endl;

	cout << "Test the prefix-- operator\n";
	m.setMonthName("January");
	cout << "Before pre-decrement: " << m << endl;
	--m;
	cout << "After pre-decrement:  " << m << endl;

	cout << "Test the postfix-- operator.\n";
	cout << "Before post-decrement: " << m << endl;
	m--;
	cout << "After post-decrement: " << m << endl << endl;

	cout << "Test stream extraction operator.\n";
	cout << "Enter a bad month name: ";
	cin >> mDefault;
	cout << "New month name is: " << mDefault << endl << endl;

	cout << "Enter a good month name: ";
	cin >> mDefault;
	cout << "New month name is: " << mDefault << endl << endl;

	return 0;
}