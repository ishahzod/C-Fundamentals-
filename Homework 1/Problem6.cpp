#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <conio.h>
using namespace std;

/*NOTE: While running the program, press any button to continue the text*/
/*This is because the program pauses when matching the word*/

/*Declaring global variables to be used in all functions*/
char c;
FILE *fp;

void getc(int match, char word[]);
int main() 
{
	int i, match = 0;
	char word[] = "mathematician";
	fp = fopen("Cauchy.dat", "r");
	getc(match, word);
	
	/*While not the end of file, look for the word and increment match each time we find it*/

	while (!feof(fp)) 
	{
		for (i = 0; word[i] != '\0'; i++) 
		{
			if (word[i] == c) 
			{
				putchar(c);
				getc(match, word);

			}
			else 
			{
				i = -1 ;
				putchar(c);
				getc(match, word);
			}
		}
		_getch();
		match++;

	}
	fclose(fp);
	system("pause");
	return 0;
}

void getc(int match, char word[]) 
{
	c = fgetc(fp);
	if (feof(fp))
	{
		cout << endl << "End of File." << endl;
		cout << "The word '" << word << "' appears " << match << " times." << endl;
		system("pause");
		exit(1);

	}
}
