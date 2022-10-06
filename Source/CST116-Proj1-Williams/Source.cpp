#include <iostream>
#include <windows.h> //used for printing fancy colored text
#include <vector> //Vectors are lists of things...including other vectors.
using namespace std;

//Prints in full color with (optional) automatic line breaks. Returns nothing and takes up to 4 parameters:
//console (HANDLE): Used for colored text. Always set it to hConsole and don't worry about it.
//text (string): The text to be printed. Don't put a newline at the end.
//color (int): The color code of the text. Optional, defaults to white.
//linebreak (bool): Whether to end the line after printing. Optional, defaults to true.
void colorPrint(HANDLE console, string text, int color = 15, bool linebreak = true)
{
	if (linebreak) //Add a line break to the end of the text unless told not to
	{
		text += "\n";
	}
	SetConsoleTextAttribute(console, color); //Use black magic (native OS commands) to change the color of any text we print.
	cout << text;
	SetConsoleTextAttribute(console, 15); //Use more black magic to set the color back to white so that we don't start randomly printing other colors.

}

//Prints a prompt in full color, then gets a string input from the user. Returns a string and takes up to 4 parameters.
//console (HANDLE): Used for colored text. Always set it to hConsole and don't worry about it.
//text (string): The text to be printed. Don't put a newline at the end.
//color (int): The color code of the text. Optional, defaults to white.
//newline (bool): Whether to end the line after printing. Optional, defaults to true.
string getInput(HANDLE console, string text, int color = 15, bool linebreak = false)
{
	string input;
	if (linebreak) //Add a line break to the end of the text unless told not to
	{
		text += "\n";
	}
	SetConsoleTextAttribute(console, color); //Use black magic (native OS commands) to change the color of any text we print.
	cout << text;
	SetConsoleTextAttribute(console, 15); //Use more black magic to set the color back to white so that we don't start randomly printing other colors.
	cin >> input;
	return input;
}




int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	vector <string> names, incomes, gpas; //Create 3 lists to hold the different values.

	return 0;
}