
//This will work with array sizes up to 99x99 allowing the user the choice to manually input elements or generate them randomly
//I could have kept it short, but I wanted to optimize it to run for larger array sizes entered by the user

#include<stdio.h>
#include <iostream>
#include <time.h>
#define ROWS 99
#define COLUMNS 99
using namespace std;

void setZero(int a[][COLUMNS], int r, int c);
int GenerateRandom(int a[][COLUMNS], int r, int c);
void Test(int arrN[4][3])                                //Sample Test for the given Array: arrN[4][3]
{
	cout << "Sample Array: " << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arrN[i][j]);
		}

		puts("");
	}

	cout << endl << "Transformed Array: " << endl;

	int col[COLUMNS] = { 0 };

	int row[ROWS] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!arrN[i][j]) //Marks the rows and columns not to copy
			{
				col[j] = 1;
				row[i] = 1;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (col[j] == 1 || row[i] == 1)//Ignores marked elements and sets everything else to zero

				arrN[i][j] = 0;
		}
	}

	for (int i = 0; i < 4; i++)     //Transformed array
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arrN[i][j]);
		}

		puts("");
	}
}

int main()

{
	int r, c; char k;
	int a[ROWS][COLUMNS];
	int arrN[4][3] = { { 5, 1, 0 },{ 3, 2, 4 },{ 39, 20, 0 },{ 11, 2, 49 } };// Given array

	Test(arrN);

	int col[COLUMNS] = { 0 };

	int row[ROWS] = { 0 };
	//Prompts user to choose how they want to fill the array
	cout << endl << "Please enter the number of rows for the array: ";
	cin >> r;

	cout << "Please enter the number of columns for the array: ";
	cin >> c;

	cout << "Enter: " << endl << "a) To input elements manually\n\t\tor" << endl << "b) To Generate random elements\n" << endl;
	cin >> k;

	if (k == 'a')
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << "Enter Values for[" << i << "][" << j << "] : ";
				cin >> a[i][j];
			}
		}
		setZero(a, r, c);
	}
	else if (k == 'b') 
	{
		GenerateRandom(a, r, c);     
		setZero(a, r, c); 
	}
	else
	{
		cout << "\nPlease choose one of the options.\n" << endl;
		main();
	}

}

void setZero(int a[][COLUMNS], int r, int c)
{
	cout << "Original Array [" << r << "]["<< c << "]" << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
		}
		puts("");
	}

	cout << "Transformed [" << r << "][" << c << "]" << endl;

	int col[COLUMNS] = { 0 };

	int row[ROWS] = { 0 };

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (!a[i][j]) {

				col[j] = 1;
				row[i] = 1;
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (col[j] == 1 || row[i] == 1)

				a[i][j] = 0;
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
		}

		puts("");
	}
	system("pause");
}

int GenerateRandom(int a[][COLUMNS], int r, int c)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i<r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] = rand() % 100;
		//	cout << arr[i][j] << endl;
		}
	}
	return **a;
}