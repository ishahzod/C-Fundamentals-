#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int main()
{
	int const size = 10;
	int a[size] = { 5, 99, 62, 52, 11, 44, 69, 42, 20, 19 };
	int *ptra; 

	ptra = &a[0]; //points to the first element of array a

	cout << "a[" << size << "]: " << endl << "{ ";
	for (int i = 0; i < size; i++)
	{
		cout << *(ptra + i) <<  ", ";
	}
	cout << "}" << endl; 
	system("pause");
	return 0;
}


/*

ptr++;    // Pointer moves to the next int position (as if it was an array)
++ptr;    // Pointer moves to the next int position (as if it was an array)
++*ptr;   // The value of ptr is incremented
++(*ptr); // The value of ptr is incremented
++*(ptr); // The value of ptr is incremented
*ptr++;   // Pointer moves to the next int position (as if it was an array). But returns the old content
(*ptr)++; // The value of ptr is incremented
*(ptr)++; // Pointer moves to the next int position (as if it was an array). But returns the old content
*++ptr;   // Pointer moves to the next int position, and then get's accessed, with your code, segfault
*(++ptr); // Pointer moves to the next int position, and then get's accessed, with your code, segfault


*/