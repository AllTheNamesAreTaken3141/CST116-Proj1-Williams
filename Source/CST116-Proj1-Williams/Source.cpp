#include <iostream>
#include <iomanip>
#include <sstream>
#include <windows.h> //Used for printing fancy colored text.
#include <vector> //Vectors are lists of things...including other vectors.
#include <string> //Fancy advanced string functions (used mainly for finding the length of a string.
#include <tuple> //Tuples are a different type of list. They can contain multiple data types (unlike a vector), but are also a lot more inconvenient to work with and have a fixed length, which is why I'm using vector's whenever possible.
#include <algorithm> //So many libraries...so many libraries.
#include <cmath> //Used for rounding and exponents.
using namespace std;
using std::cout;
const int DECIMAL_PRECISON = 2;

//Making constants all caps is a python habit I carried over to C++. It doesn't affect the program at all but it does make it easier to see what variables are constants at a glance.
const HANDLE HCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);

//Uses black magic to print in full color with (optional) automatic line breaks. Requires <windows.h>. Returns nothing and takes up to 4 parameters:
//text (string): The text to be printed. Don't put a newline or endl at the end.
//color (int): The color code of the text. Optional, defaults to white.
//linebreak (bool): Whether to end the line after printing. Optional, defaults to true.
//console (HANDLE) the console the function is printing to, used for changing color. Defaults to HCONSOLE, so as long as you define the console as HCONSOLE somewhere, you can probably ignore it.
void colorPrint(string text, int color = 15, bool linebreak = true, HANDLE console = HCONSOLE)
{
	SetConsoleTextAttribute(console, color); //Change the output color to whatever is chosen for the text (defaults to 15, which is white).
	cout << text;
	SetConsoleTextAttribute(console, 15); //Use moret the color back to white so that we don't start randomly printing other colors.
	if (linebreak) //Add a line break to the end of the text unless told not to
	{
		cout << endl;
	}
}

//Prints a prompt in full color, then gets a string input from the user. Returns a string and takes up to 4 parameters:
//text (string): The text to be printed. Don't put a newline at the end.
//color (int): The color code of the text. Optional, defaults to white.
//newline (bool): Whether to end the line after printing but before input. Optional, defaults to false.
//console (HANDLE): Used for colored text. Always set it to HCONSOLE and don't worry about it.
string getStringInput(string text, int color = 15, bool linebreak = false, HANDLE console = HCONSOLE)
{
	string input;
	colorPrint(text, color, linebreak, console);
	cin.get();
	getline(cin, input);
	if (linebreak) //Add a line break to the end of the text unless told not to
	{
		cout << endl;
	}

	return input; //Send the input to whatever variable the function is passed to.
}

//Prints a prompt in full color, then gets a float input from the user. Returns a string and takes up to 4 parameters:
//text (string): The text to be printed. Don't put a newline at the end.
//color (int): The color code of the text. Optional, defaults to white.
//newline (bool): Whether to end the line after printing but before input. Optional, defaults to false.
//console (HANDLE): Used for colored text. Always set it to HCONSOLE and don't worry about it.
float getFloatInput(string text, int color = 15, bool linebreak = false, HANDLE console = HCONSOLE)
{
	float input;
	if (linebreak) //Add a line break to the end of the text unless told not to
	{
		text += "\n";
	}
	cin.sync();
	while (true)
	{
		colorPrint(text, color, linebreak, console);
		if (cin >> input) //Tests if the input is a valid number and ends the loop if it is.
		{
			return input; //Immediately exit the function and return the input.
		}
		colorPrint("Error: Your input must be a number. Please try again.", 12);
		cin.clear();
		cin.ignore(80, '\n');
	}
}

//Returns the length of the longest string in a vector (of strings). Requires <vector> and <element>. Takes 1 parameter, which is the vector to be calculated.
int maxLength(vector <string> data) {
	int longest = 0;

	for (string s : data)
	{
		int currentLength = (int)s.length();

		if (currentLength > longest)
		{
			longest = currentLength;
		}
	}

	return longest;
}

//Really, *really* fancy table printer.
void dynamicTable(vector <vector <string> > data, int headingColor = 15, int dataColor = 15, string separator = "|", int verticalColor = 15, HANDLE console = HCONSOLE)
{
	vector <int> columnWidths; //Holds the maximum length of each column.

	for (vector <string> i : data)
	{
		columnWidths.push_back(maxLength(i));
	}

	cout << left;

	for (int r = 0; r < data[0].size(); r++)
	{
		colorPrint(separator, verticalColor, false);

		for (int c = 0; c < data.size(); c++)
		{
			cout << setw(columnWidths[c]);
			if (r == 0)
			{
				colorPrint(data[c][r], headingColor, false);

			}
			else {
				colorPrint(data[c][r], dataColor, false);
			}
			
			colorPrint(separator, verticalColor, false);
		}
		cout << endl;
	}
}


void dynamicTableMember(vector <vector <string> > data, int headingColor = 15, int dataColor = 15, string separator = "|", int verticalColor = 15, HANDLE console = HCONSOLE)
{
	vector <int> columnWidths; //Holds the maximum length of each column.

	for (vector <string> i : data)
	{

		columnWidths.push_back(maxLength(i));
	}

	cout.setf(ios::left, ios::adjustfield);

	for (int r = 0; r < data[0].size(); r++)
	{
		colorPrint(separator, verticalColor, false);
		for (int c = 0; c < data.size(); c++)
		{
			cout.width(columnWidths[c]);
			if (r == 0)
			{
				colorPrint(data[c][r], headingColor, false);

			}
			else {
				colorPrint(data[c][r], dataColor, false);
			}
			colorPrint(separator, verticalColor, false);
		}
		cout << endl;
	}
}


int main()
{
	vector <string> names = { "Name:"};
	vector <string> tableIncomes = { "Income:" };
	vector <string> tableAges = { "Age:" };
	vector <string> tableGPAs = { "GPA:" };

	vector <float> incomes = {5214.61, 9521.5521, 666.666, 2152};
	vector <float> ages = {};
	vector <float> GPAs = {3.8, 4.0, 0, 3.1};

	for (int i = 0; i < 4; i++) {
		names.push_back(getStringInput("Please enter your name: "));
		incomes.push_back(getFloatInput("Please enter your income: "));
		GPAs.push_back(getFloatInput("Please enter your GPA: "));
	}

	for (float i : incomes)
	{
		stringstream stream;
		stream << fixed << setprecision(2) << i;
		tableIncomes.push_back("$" + stream.str());
	}

	for (float i : GPAs)
	{
		stringstream stream;
		stream << fixed << setprecision(2) << i;
		tableGPAs.push_back(stream.str());
	}

	vector <vector <string> > GPATable = {names, tableIncomes, tableGPAs};
	dynamicTableMember(GPATable, 9);
	names = { "Name:" };
	tableIncomes = { "Income:" };
	incomes = {};
	
	for (int i = 0; i < 4; i++) {
		names.push_back(getStringInput("Please enter your name: "));
		incomes.push_back(getFloatInput("Please enter your income: "));
		ages.push_back(getFloatInput("Please enter your age: "));
	}

	for (float i : incomes)
	{
		stringstream stream;
		stream << fixed << setprecision(2) << i;
		tableIncomes.push_back("$" + stream.str());
	}

	for (float i : ages)
	{
		stringstream stream;
		stream << fixed << setprecision(2) << i;
		tableAges.push_back(stream.str());
	}
	
	vector <vector <string> > ageTable = {names, tableIncomes, tableAges};
	dynamicTableMember(ageTable, 9);

	return 0;
}