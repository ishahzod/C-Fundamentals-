#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <cmath>
#include <iostream>
#define accuracy 0.00001
using namespace std;

double exp(double x, int n);
double fac(int f); 

int main()
{
	double x, sum;
	cout << "Please enter a value for x: "; 
	cin >> x;

		sum = exp(x);

		cout << "Solution: " << sum << endl;


    /*Input Validation*/
	while(!(cin >> x))
	{ 
		cout << "\nPlease enter a numeric value.\n\n";
		cin.clear();                                            //clears input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');    //sets cin to ignore all/any input characters upto \n
	    main();                                                 //return to the main() function
	}

	getchar();//system("pause");
	return 0;
}

double exp(double x, int n)
{
	double e, sum=0;
	
	for(int i = 1; i<= n; i++)
	{
		e = (pow(x, i)) / fac(i);
		if (e < accuracy) { break; }        
		sum += e;
	}
	return sum;
}

double fac(int n)
{
	int fac = 1;
	for (n; n>1; n++) 
	{
		fac *= n;
	}

	return fac; 

}