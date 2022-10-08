#include <iostream>
#include <windows.h> //used for printing fancy colored text.
#include <vector> //Vectors are lists of things...including other vectors.
#include <string> //Fancy advanced string functions (used mainly for finding the length of a string.
#include <algorithm> //So many libraries...so many libraries.
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
//newline (bool): Whether to end the line after printing but before input. Optional, defaults to false.
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
	return input; //Send the input to whatever variable the function is passed to.
}

//Returns the length of the longest element in a vector.
int maxLength(vector <string> data) {
	auto longest = *max_element(data.begin(), data.end(), [](const auto& s1, const auto& s2) { return s1.size() < s2.size(); });
	return longest.length();
}

//Really, *really* fancy table printer.
void dynamicTable(HANDLE console, vector <vector <string> > data, size_t maxWidth = -1, int headingColor = 15, int dataColor = 15, int verticalColor = 15, int horizontalColor = 15)
{
	vector <int> columnWidths; //holds the maximum length of each column
	
	for (vector <string> i : data)
	{
		columnWidths.push_back(maxLength(i));
	}

	for (int r = 0; r < data[0].size(); r++)
	{
		colorPrint(console, "|", verticalColor, false);
		for (int c = 0; c < data.size(); c++)
		{
				
			colorPrint(console, "|", verticalColor, false);
		}
		cout << endl;
	}
}

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	vector <string> names = { "Name" };
	vector <string> ages = { "Age" };
	vector <string> gpas = { "GPA" };

	for (int i = 0; i < 4; i++)
	{
		names.push_back(getInput(hConsole, "Enter your name: "));
		ages.push_back(getInput(hConsole, "Enter your age: "));
		gpas.push_back(getInput(hConsole, "Enter your GPA: "));
	}

	return 0;
}