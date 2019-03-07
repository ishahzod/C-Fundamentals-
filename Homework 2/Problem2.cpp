#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int Add(int x, int y);

int main()
{
	int x, y, sum; 
	cout << " Please enter the two integers you want to add: "; 
	cin >> x >> y; 
	sum = Add(x, y);
	cout << "Sum: "<< sum << endl; 

	system("Pause");
	return 0;
}

int Add(int x, int y) 
{
	{
		// Loops until there is no carry  
		while (y != 0)
		{
			// carry now contains common set bits of x and y
			int carry = x & y;

			// Sum of bits of x and y where at least one of the bits is not set
			x = x ^ y;

			// Carry is shifted by 1, such that adding it will sum the terms
			y = carry << 1;
		}
		return x;
	}
}