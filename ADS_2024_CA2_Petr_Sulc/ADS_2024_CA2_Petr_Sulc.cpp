// ADS_2024_CA2_Petr_Sulc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ApplicationPart2.h"

void part2()
{
	ApplicationPart2 app;
	app.LoadFile("WordListPart2.txt");

	cout << "Part 2:" << endl;
	bool quit = false;
	while (!quit)
	{
		cout << "\n1 - print keys\n2 - print values\n3 - quit\n Input: ";
		string in;
		cin >> in;
		if (in == "1")
		{
			cout << endl;
			app.PrintKeys();
		}
		else if (in == "2")
		{
			cout << "Choose a letter: ";
			cin >> in;
			cout << endl;
			app.PrintValues(in[0]);
		}
		else if (in == "3")
		{
			quit = true;
		}
		else
		{
			cout << "Invalid command" << endl;
		}
	}
}


int main()
{
	part2();
}
