#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define MAX 9999
using namespace std;

int SortArray(int arr[], int n);
int GenerateFromArray(int arr[],int n);
void Sum(int arr[], int n, int s);


/*ALGORITHM*/
/*

1) Let user input the array size
2) Prompt them to either enter the elements manually or with a random number generator
3) Sort the array 
4) Prompt the user for a specified sum 
5) Compare the sum of the first and last elements of the array and move towards the middle of the array

*/



int main() 
{
	int arr[MAX], n, s; char c;
	cout << "Please enter array size n: "; 
	cin >> n; 

	/*Prompts user to choose how they want to fill the array*/

	cout << "Enter:\na) To input elements manually\n\t\tor\nb) To Generate random elements\n" << endl;
	cin >> c; 
	
    if (c == 'a')
	{
		cout << "Please enter " << n << " integers followed by a space: " << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i]; 
		}
	}
    else if (c == 'b')
	{
		GenerateFromArray(arr, n);
	}
	else
	{
		cout << "\nPlease choose one of the options.\n" << endl;
		main();
	}

	SortArray(arr, n);

	cout << "Enter the desired sum: "; 
	cin >> s; 

	Sum(arr, n, s);

	system("pause");
	return 0;
}

void Sum(int arr[], int n, int s)
{
	int i = 0; 
	int j = n - 1;

	/*Compares the 1st and last element of the array and moves towards middle*/
	while (i < j)
	{
		if (arr[i] + arr[j] == s)
		{
			cout << arr[i] << " " << arr[j] << endl;
			i++;
		}
		else if (arr[i] + arr[j] < s)
		{
			i++;
		}
		else if (arr[i] + arr[j] > s)
		{
			j--;
		}
		else if (!(arr[i] + arr[j] == s))
		{
			cout << "No matching pairs were found.";
		}
	}
}

int GenerateFromArray(int arr [], int n) {

	srand((unsigned int)time(NULL));

	for (int i = 0; i<n; i++) 
	{
		arr[i] = rand() % 1000;
		cout << arr[i] << endl;

	}
	return *arr;
}

int SortArray(int arr[], int n)
{
	int i, j, temp; 

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++) 
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

	}
	cout << endl << "Sorted Array: \n{";
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "}\n"<< endl;
	return *arr; 
}