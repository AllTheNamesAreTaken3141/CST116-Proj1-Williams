#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 15; i++)
	{
		cout << "Hello World!" << endl;
		SetConsoleTextAttribute(hConsole, i);
	}

	return 0;
}