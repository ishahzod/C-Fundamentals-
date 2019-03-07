
//function decleration 
//Complex.h

#include <iostream>
using namespace std;

#ifndef Complex_H
#define Complex_H

class Complex
{
public:

	double real;
	double imag;

	//default constructor
	Complex();

	~Complex(); //destructor 

	Complex(float, float);

	//operators
	friend ostream& operator<< (ostream &out, const Complex &c);
	friend Complex operator+ (const Complex &num1, const Complex &num2);
	friend Complex operator- (const Complex &num1, const Complex &num2);
	friend Complex operator* (const Complex &num1, const Complex &num2);
	friend Complex operator/ (const Complex &num1, const Complex &num2);
	friend bool Complex::operator!=(const Complex &num1, const Complex &num2);
	friend bool Complex::operator==(const Complex &num1, const Complex &num2);
	Complex operator~ ();
	friend double  Complex::Polar(const Complex &num);
	friend  double Complex::Magnitude(const Complex &num);

};
#endif

