//Main.cpp

#include <iostream>
#include "Problem4 Complex.h"

using namespace std;

int main()
{
	float K, L, M, N;

	//prompts user to enter complex numbers

	cout << "Please real part followed by the imaginary part: " << endl;
	cin >> K;
	cin >> L;

	cout << "Please real part followed by the imaginary part: " << endl;
	cin >> M;
	cin >> N;

	Complex a(K, L);
	Complex b(M, N);
	Complex sum = a + b;
	Complex sub = a - b;
	Complex mul = a*b;
	Complex div = a / b;
	Complex conja = ~a;
	Complex conjb = ~b;
	double mag1 = Magnitude(a);
	double mag2 = Magnitude(b);
	double pol1 = Polar(a);
	double pol2 = Polar(b);


	cout << "Complex number 1: " << a << endl;
	cout << "Complex number 2: " << b << endl;
	cout << "Sum of the two complex numbers: " << sum << endl;
	cout << "Difference of the two complex numbers: " << sub << endl;
	cout << "Product of the two complex numbers: " << mul << endl;
	cout << "Quotient of the two complex numbers: " << div << endl;
	cout << "Conjugate pair of Complex number 1: " << conja << endl;
	cout << "Conjugate pair of Complex number 2: " << conjb << endl;
	cout << "Magnitude of Complex number 1: " << mag1 << endl;
	cout << "Magnitude of Complex number 2: " << mag2 << endl;
	cout << "Polar coordinates of Complex number 1: " << pol1 << " degrees. " << endl;
	cout << "Polar coordinates of Complex number 2: " << pol2 << " degrees. " << endl;


	system("Pause");
	return 0;
}
