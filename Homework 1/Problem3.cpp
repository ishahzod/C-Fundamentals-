#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <cmath>
#include <time.h>
#include <iostream>
#define MAX 100
using namespace std;

int ScanArray(char *fname, int myArray[], int nSize);
void GenerateFromArray(int myArray[], int nSize, int mChoose);

int main()
{
	int nSize, mChoose;
	char fname[] = "ArrayInp.dat";
	int myArray[MAX];

	cout << "Please enter size of the array: ";
	cin >> nSize;

	/*Input Validation if needed*/

	//if (!(cin >> nSize) || nSize > MAX)
	//{
	//	cout << "\nError.\n Please enter a numeric value or a smaller integer size.\n\n";
	//	cin.clear();                                            //clears input
	//	cin.ignore(numeric_limits<streamsize>::max());         //sets cin to ignore all/any input characters up until next line
	//	cout << endl;
	//	main();                                                 //return to the main() function
	//}

	//else

	ScanArray(fname, myArray, nSize);

	cout << "Reading File... \nmyArray [" << nSize << "] = {"; 
	for (int i = 0; i < nSize; i++)
	{
		cout << myArray[i] << ", " ;
	}
	cout << "}\n" << "\n Indexed: \n" << endl; 

	for (int i = 0; i < nSize; i++)
	{
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}
	cout << "\nHow many random integers would you like to generate? ";
	cin >> mChoose;
	cout << endl;

	/*Input Validation if needed*/

	//if (!(cin >> mChoose) || mChoose > nSize)
	//{
	//	cout << "\nError.\nYou did not enter a numeric value or the number exceeds the size of the array.\n\n";
	//	cin.clear();                                            //clears input
	//	cin.ignore(numeric_limits<streamsize>::max());         //sets cin to ignore all/any input characters up until next line
	//	main();                                                 //return to the main() function
	//}

	//else
	{
		GenerateFromArray(myArray, nSize, mChoose);
	}

	system("pause");
	return 0; 
}


int ScanArray(char *fname, int myArray[], int nSize)
{


	FILE *fp;
	//fp = fopen("C:\\Users\\ishah\\Desktop\\Spring 2017\\ESE224\\ArrayInp.dat", "r"); 
	fp = fopen("ArrayInp.dat", "rt");

	if (fp == NULL)
	{
		cout << "File " << fname << " not found." << endl;
	}
	else
	{
		for (int i = 0; i < nSize; i++)
		{
			fscanf(fp, "%d", &myArray[i]);
		}
		fclose(fp);
	}
	return *myArray; 
}

void GenerateFromArray(int myArray[], int nSize, int mChoose)
{
	int ri = 0, eveni, oddi;

	/* seeds random number generator with current time */
	srand((unsigned int)time(NULL));

	for (int j = 0; j < mChoose; j++)
	{
		myArray[ri] = rand() % nSize;

		eveni = myArray[ri % 2 == 0];
		oddi = myArray[ri % 2 == 1];
		
		/*Prints out twice as many even indexed elements as odd*/

		if (2/3 * mChoose > j)
		{
			cout <<  myArray[eveni] << endl;
		}
		else if (2/3 * mChoose <= j)
		{
			cout  << myArray[oddi] << endl;
		}
	}
}

	