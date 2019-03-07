#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	char c;
	//while (true) {                            //loops the function infinitely if needed
		cout << "Enter any character: ";
		cin >> c;

		if (c >= 'a' && c <= 'z')       
		{
			cout << c << " is a lowercase letter." << endl; 
		}

		else if (c >= 'A' && c <= 'Z')
		{
			cout << c << " is an uppercase letter." << endl;
		}
		else if ((isdigit(c)))                   //(c >= 0 && c <= 9)    //checks if input c is a digit
		{
			cout << c << " is a digit." << endl;
		} 
		else if (!(isalnum(c)))                  //too many if/then restrictions, used function to check alphanumeric input
		{
			cout << c << " is a special character." << endl;
		}
		cout << endl; 
		system("pause");
	//}                                                    //end loop  
	return 0;

}


