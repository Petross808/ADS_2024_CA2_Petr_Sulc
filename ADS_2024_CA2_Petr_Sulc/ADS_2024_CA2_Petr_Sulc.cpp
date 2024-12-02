// ADS_2024_CA2_Petr_Sulc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ApplicationPart2.h"
#include "ApplicationPart4.h"

void static part2()
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

void static part4()
{
	ApplicationPart4 app;
	cout << "Part 4:" << endl;
	bool quit = false;
	while (!quit)
	{
		cout << "\n0 - load data\n1 - print keys\n2 - print values\n3 - quit\n Input: ";
		string in;
		cin >> in;
		if (in == "0")
		{
			cout << "\nChoose an index:\n1 - ID\n2 - First Name\n3 - Last Name\n4 - Age\n5 - Email\n6 - Score\n7 - Passed\n Input: ";
			cin >> in;
			cout << endl;
			switch (in[0])
			{
			case '1':
				app.LoadFile("randomData.csv", Entity::ID);
				break;
			case '2':
				app.LoadFile("randomData.csv", Entity::FIRST_NAME);
				break;
			case '3':
				app.LoadFile("randomData.csv", Entity::LAST_NAME);
				break;
			case '4':
				app.LoadFile("randomData.csv", Entity::AGE);
				break;
			case '5':
				app.LoadFile("randomData.csv", Entity::EMAIL);
				break;
			case '6':
				app.LoadFile("randomData.csv", Entity::SCORE);
				break;
			case '7':
				app.LoadFile("randomData.csv", Entity::PASSED);
				break;
			default:
				cout << "Invalid command" << endl;
			}
		}
		else if (in == "1")
		{
			cout << endl;
			app.PrintKeys();
		}
		else if (in == "2")
		{
			cout << "Choose a key: ";
			cin >> in;
			cout << endl;
			app.PrintValues(in);
		}
		else if (in == "3")
		{
			cout << "\nGoodbye\n";
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
	string in;
	cout << "1 - Part 2 Application\n2 - Part 4 Application\n Input: ";
	cin >> in;
	if (in[0] == '2')
		part4();
	else
		part2();
}
