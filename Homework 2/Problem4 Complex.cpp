//function definitions
//Complex.cpp

#include "Problem4 Complex.h"
#include <cmath>

Complex::Complex()
{
	real = 0.0;
	imag = 0.0;
}

Complex::~Complex()
{
}

Complex::Complex(float r, float i)
{
	real = r;
	imag = i;
}


//displays the complex number

ostream & operator<<(ostream & out, const Complex & c)
{
	out << c.real << "+" << c.imag << "i";
	return out;
}

//various operations applied to the two complex numbers

Complex operator+(const Complex & num1, const Complex & num2)
{
	Complex answer;

	answer.real = num1.real + num2.real;
	answer.imag = num1.imag + num2.imag;
	return answer;
}


Complex operator- (const Complex &num1, const Complex &num2)
{
	Complex answer;

	answer.real = num1.real - num2.real;
	answer.imag = num1.imag - num2.imag;

	return answer;
}

Complex operator* (const Complex &num1, const Complex &num2)
{
	Complex answer;

	answer.real = (num1.real * num2.real - num1.imag * num2.imag);
	answer.imag = (num1.real * num2.imag + num1.imag * num2.real);

	return answer;
}

Complex operator/ (const Complex &num1, const Complex &num2)
{
	Complex answer;

	answer.real = (num1.real * num2.real + num1.imag * num2.imag) / (num2.real * num2.real + num2.imag * num2.imag);
	answer.imag = (num1.imag * num2.real - num1.real * num2.imag) / (num2.real * num2.real + num2.imag * num2.imag);

	return answer;
}

//compares the two complex numbers

bool operator==(const Complex &num1, const Complex &num2) {
	if (num1.real == num2.real && num1.imag == num2.imag) {
		return true;
	}
	else {
		return false;
	}
}
bool operator!=(const Complex &num1, const Complex &num2) {
	if (num1.real == num2.real && num1.imag == num2.imag) {
		return false;
	}
	else {
		return true;
	}
}

// computes the magnitude and polar coordinates

double Magnitude(const Complex &num)
{
	double answer;
	answer = sqrt(pow(num.real, 2) + pow(num.imag, 2));

	return answer;
}

double Polar(const Complex & num)
{
	double answer;
	answer = tan(num.imag / num.real);

	return answer;
}


//conjugate pair

Complex Complex::operator~()
{
	Complex answer;
	answer.real = real;
	answer.imag = -imag;

	return answer;
}


