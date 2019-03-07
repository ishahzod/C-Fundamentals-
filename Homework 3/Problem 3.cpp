#include<iostream>

using namespace std;

class Array
{
	int size;
	int *arr;
public:
	Array() {}
	Array(int size);
	Array(Array &arr);
	void display();
	void sort();
	void addElements();
	Array& operator+(Array &arr1); 
	void operator=(Array &arr);
	int& operator[](int i);
	int getSize() 
	{
		return size;
	}
};

Array::Array(int s)
{
	size = s;
	arr = new int[size];
}

Array::Array(Array &a)
{
	size = a.size;
	arr = new int[size];  //utilizing memory allocation 
	for (int i = 0; i<size; i++)
	{
		arr[i] = a[i];
	}
}

int& Array::operator[](int i)
{
	if (i > size)
	{
		cout << "Index out of bounds" << endl;
		return arr[0];
	}
	return arr[i];
}
// adds user entered elements to the array
void Array::addElements()
{
	cout << "Add " << size << " elements to the array: ";
	for (int i = 0; i<size; i++)
	{
		cin >> arr[i];
	}
}
//displays the array
void Array::display()
{
	for (int i = 0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
// sorts the array from least to greatest
void Array::sort()
{
	int i, j, temp;
	for (i = 1; i<size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp<arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else break;
		}
		arr[j + 1] = temp;
	}
}
// adds the two arrays to make 
Array& Array::operator+(Array &arr1)
{
	Array a(size + arr1.size);

	int i;
	for (i = 0; i<size; i++)
		a[i] = arr[i];
	for (i; i<(size + arr1.size); i++)
		a[i] = arr1[i - size];
	a.display();
	return a;
}

void Array::operator=(Array &arr1)
{
	size = arr1.size;
	for (int i = 0; i<size; i++)
		arr[i] = arr1[i];
}

int main()
{
	int ch;
	cout << "Creating an array...\n";
	int size;
	cout << "\nEnter the size of the first array: ";
	cin >> size;
	Array arr1(size);
	cout << "Enter elements\n";
	for (int i = 0; i<arr1.getSize(); i++)
		cin >> arr1[i];

	cout << "Display array elements\n";
	cout << "\n\nElements in the array are: ";
	arr1.display();

	cout << "Sort array\n";
	arr1.sort();
	cout << "\nAfter sorting elements are: ";
	arr1.display();

	cout << "Add two arrays to form one array\n";
	cout << "\nEnter the size of the second array: ";
	cin >> size;
	Array arr2(size);
	cout << "\nEnter elements: " << endl;
	for (int i = 0; i < arr2.getSize(); i++)
	{
		cin >> arr2[i];
	}
	cout << "Combining the first and the second array: " << endl;
	Array arr3;
	arr3 = arr1 + arr2;
	arr3.display();

	system("pause");
	return 0;
}