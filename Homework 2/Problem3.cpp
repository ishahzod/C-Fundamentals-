#define _crt_secure_no_warnings
#include <iostream>
#include <string>
#include <fstream>
#include <cmath> 
using namespace std;

//note to grader: Please specify file path if the code does not work 

FILE *fp;
	using namespace std;
	int main() {
		string a[10000];	//Storing words in this array
		string of1[10000];  //overflow 1
		string of2[10000];	//over flow 2
		const string name[6] = //array of strings 
		{ "Magazine1.dat", "Magazine2.dat", "Magazine3.dat", "Magazine4.dat", "Magazine5.dat", "Magazine6.dat" };

		cout << "Reading... "<<endl;
		for (int i = 0; i < 6; i++) {
			cout << i+1 << " Articles Read: "<<endl;
			ifstream file(name[i]);
			if (file.is_open()) {

				for (int i = 0; i < 500; i++)
				{
					string temp[2000];   //temp string to hold values
					file >> temp[i];


					int sum = 0;

					string str = temp[i];
					for (unsigned int n = 0; n < str.size(); n++) { //Hashing function to get a[] values
						sum += str[n];
					}
					if (a[sum].empty() || a[sum] == " " || !a[sum].compare(temp[i])) { //makes sure that space to assign value is empty a space or a duplicate
						a[sum] = temp[i];
					}
					else {
						if (of1[sum].empty() || of2[sum] == " " || !of1[sum].compare(temp[i])) { //if last one was full check here
							of1[sum] = temp[i];

						}
						else if (of2[sum].empty() || of2[sum] == " " || !of2[sum].compare(temp[i])) { //repeat for of2
							of2[sum] = temp[i];
						}
					}
				}
			}

			else {
				cout << "Cannot open magazine file. Please check file location and try again." << endl;
				
			}
		}
		cout << endl;
		cout << "Reading Note ..."<<endl;
		int q = 0;
		 //counter for checking if not can be compiled
		ifstream file("RansomNote.dat"); 
		if (file.is_open()) { //opens ransomnote file
			string myArray[30]; //string to hold words in file

			for (int i = 0; i < 23; ++i)
			{
				int sum = 0;
				file >> myArray[i];

				for (auto &c : myArray[i])  //loop checks every character to remove puncuation, 
				{
					if (ispunct(c) && myArray[i].size()==1) //to see if its a punctuation and one long, too avoid loosing $ on $10,000
					{
						c = ' ';       //if so it replaces it with a blank space.(delete) 
					}

				}
				if (myArray[i].empty() || myArray[i] == " ") {
					continue; // if myarray was puncuation or space or empty restart loop
				}

				string s = myArray[i];
				for (unsigned int n = 0; n < s.size(); n++) {
					sum += s[n];
				}
				//cout << sum;
				cout << myArray[i] << "    ";
				if (a[sum].empty() || a[sum] == " ") { //compares hash values with the first stored word if nothing is there 
					q++;
					cout << "the case-senstive word   '" << myArray[i] << "'    wasn't found in the articles" << endl;
				}
				else {
					if (!myArray[i].compare(a[sum])) { //compare string values and checks the word to see if it the same word
						cout << "Matching word '" << myArray[i] << "' was found    ";
						cout << a[sum] << endl;
					}
					else {
						if (!myArray[i].compare(of1[sum])) {//compares string values and checks if the words are matching
							cout << "Matching word '" << myArray[i] << "' was found     ";
							cout << of1[sum] << endl;
						}
						else {
							if (!myArray[i].compare(of2[sum])) {//compares string values and checks if the words are matching
								cout << "Matching word '" << myArray[i] << "' was found     ";
								cout << of2[sum] << endl;
							}
							else {
								q++;
								cout << "No match was found" << endl; //if none of the others, than no match
							}
						}
					}
				}
			}
		}
		else {
			cout << "Cannot open RansomeNote file" << endl; //cant open file

		}
		if (q == 0){
			cout << "The note can be compiled" << endl;
		}
		else {
			cout << "Cannot be compiled due to" << q << " errors"<<  endl;
		}
		system("pause");
		

	}

