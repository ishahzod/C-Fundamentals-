#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

/*Midterm 1 Material*/
//4 Questions 80 points

//Definitely Question on Strings CHAPTER 4 and CHAPTER 16
// Problem on algorithm (HW2 #1) 
// Problem on classes (structure)
// Memory allocation 

// Read code and tell what it outputs

/*Chapter 4 Arrays and Strings*/

short things[] = { 1, 5, 3, 8 }; //Compiler automatically makes things an element of 4

char cat[8] = { 'f', 'a', 't', 'e', 's', 's', 'a', '\0' }; // a string!
char bird[11] = "Mr. Cheeps"; // the \0 is understood
char fish[] = "Bubbles";      // let the compiler count

char constant uses single quotes ' '
string constant uses double quotes ""

#include <iostream>
#include <string>
#include <cstring> //C-styled string library

int main()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "Enter your name:\n";
	cin.getline(name, ArSize); // reads through newline 
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);   //reads into array dessert
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";

	str3 = str1 + str2;
	is same as:
	strcpy(charr1, charr2); // copy charr2 to charr1
	strcat(charr1, charr2); // append contents of charr2 to char1

	int len1 = str1.size(); // obtain length of str1
	int len2 = strlen(charr1); // obtain length of charr1

	//This is the code for reading a line into a string object :
	getline(cin, str);

	return 0;
}

//Structures

Example:

#include <iostream>
struct inflatable // structure declaration
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable guest =
	{
		"Glorious Gloria", // name value
		1.88, // volume value
		29.99 // price value
	}; // guest is a structure variable of type inflatable
	   // It's initialized to the indicated values
	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	}; // pal is a second variable of type inflatable
	   // NOTE: some implementations require using
	   // static inflatable guest =
	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n";
	// pal.name is the name member of the pal variable
	cout << "You can have both for $";
	cout << guest.price + pal.price << "!\n";
	return 0;
}


//Pointers, new and delete



ptr++; // Pointer moves to the next int position (as if it was an array)
++ptr; // Pointer moves to the next int position (as if it was an array)
++*ptr; // The value of ptr is incremented
++(*ptr); // The value of ptr is incremented
++*(ptr); // The value of ptr is incremented
*ptr++; // Pointer moves to the next int position (as if it was an array). But returns the old content
(*ptr)++; // The value of ptr is incremented
*(ptr)++; // Pointer moves to the next int position (as if it was an array). But returns the old content
*++ptr; // Pointer moves to the next int position, and then get's accessed, with your code, segfault
*(++ptr); // Pointer moves to the next int position, and then get's accessed, with your code, segfault


#include <iostream>
#include <cstring> // or string.h
using namespace std;
char * getname(void); // function prototype
int main()
{
	int a[5];
	int *ptra;
	ptra = &a[0]; //points to the first element of array a
	
	char * name; // create pointer but no storage
	name = getname(); // assign address of string to name
	cout << name << " at " << (int *)name << "\n";
	delete[] name; // memory freed
	name = getname(); // reuse freed memory
	cout << name << " at " << (int *)name << "\n";
	delete[] name; // memory freed again
	return 0;
}
char * getname() // return pointer to new string
{
	char temp[80]; // temporary storage
	cout << "Enter last name: ";
	cin >> temp;
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp); // copy string into smaller space
	return pn; // temp lost when function ends
}


#include <iostream>
struct inflatable // structure definition
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;

	inflatable * ps = new inflatable; // allot memory for structure
	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20); // method 1 for member access
	cout << "Enter volume in cubic feet: ";
	cin >> (*ps).volume; // method 2 for member access
	cout << "Enter price: $";
	cin >> ps->price;
	cout << "Name: " << (*ps).name << endl; // method 2
	cout << "Volume: " << ps->volume << " cubic feet\n"; // method 1
	cout << "Price: $" << ps->price << endl; // method 1
	delete ps; // free memory used by structure
	return 0;
}


/*Chapter 8*/

//Reference Variables

int rats = 101;
int & rodents = rats; // rodents is a reference

//Both the refence and the variable have the same memory address




//Function Templates

Function templates enable you to define a function in terms of some arbitrary type.For
example, you can set up a swapping template like this:

template <typename AnyType>
void Swap(AnyType &a, AnyType &b)
{
	AnyType temp;
	temp = a;
	a = b;
	b = temp;
}

// funtemp.cpp -- using a function template
#include <iostream>
// function template prototype
template <typename T> // or class T
void Swap(T &a, T &b);
int main()
{
	using namespace std;


int i = 10;
int j = 20;
cout << "i, j = " << i << ", " << j << ".\n";
cout << "Using compiler-generated int swapper:\n";
Swap(i, j); // generates void Swap(int &, int &)
cout << "Now i, j = " << i << ", " << j << ".\n";
double x = 24.5;
double y = 81.7;
cout << "x, y = " << x << ", " << y << ".\n";
cout << "Using compiler-generated double swapper:\n";
Swap(x, y); // generates void Swap(double &, double &)
cout << "Now x, y = " << x << ", " << y << ".\n";
// cin.get();
return 0;
}
// function template definition
template <typename T> // or class T
void Swap(T &a, T &b)
{
	T temp; // temp a variable of type T
	temp = a;
	a = b;
	b = temp;
}

//Function Overloading

void print(const char * str, int width); // #1
void print(double d, int width); // #2
void print(long l, int width); // #3
void print(int i, int width); // #4
void print(const char *str); // #5
//When you then use a print() function, the compiler matches your use to the prototype
//that has the same signature :
print("Pancakes", 15); // use #1
print("Syrup"); // use #5
print(1999.0, 10); // use #2
print(1999, 12); // use #4
print(1999L, 15); // use #3


/*Chapter 9 Scopes, Storage duration, Linkage and Namespaces*/

Dynamic storage duration—Memory allocated by the new operator persists
until it is freed with the delete operator or until the program ends, whichever
comes first.This memory has dynamic storage duration and sometimes is termed
the free store or the heap.


/*Duration*/

int global = 1000; // static duration, external linkage
static int one_file = 50; // static duration, internal linkage
int main()
{
	...
}
void funct1(int n)
{
	static int count = 0; // static duration, no linkage
	int llama = 0;
	...
}

//Namespaces

namespace Jack {
	double pail; // variable declaration
	void fetch(); // function prototype
	int pal; // variable declaration
	struct Well { ... }; // structure declaration
}
namespace Jill {

	double bucket(double n) { ... } // function definition
	double fetch; // variable declaration
	int pal; // variable declaration
	struct Hill { ... }; // structure declaration
}
}



/*Chapter 10 Classes*/

#include <string>
using namespace std;

class Shaxi
{
public: // access specifier, can be accessed by other functions

	Shaxi()        //default constructor 
	{               // gets called automatically without object reference
	}

	Shaxi(string z)
	{
		setName(z);
	}


	void coolio()
	{
		cout << "Bankai" << endl;
	}

	void setName(string x)      
	{
		name = x; 
	}
	string getName()
	{
		return name;
	}
private:
	string name; 
};

int main()
{
	Shaxi ZaWarudo;  //object from that class
	Shaxi name("Tensa Zangetsu");    //Passed to Z, which passes to x
	ZaWarudo.coolio();
	name.setName("Dio");
	cout << name.getName(); // Prints out Dio 

	//Only add parameters to your constructors if you want to set initial values

	system("pause");
	return 0;
}
