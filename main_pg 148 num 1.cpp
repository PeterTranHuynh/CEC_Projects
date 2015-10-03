// Game Titles/Developers/Publishers/Consoles Manager
// Vectors and Iterators

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// List items
	const char *one = "Window's PC (CONSOLE)"; 
	const char *two = "Microsoft (PUBLISHER)";
	const char *three = "Sony (PUBLISHER)";
	const char *four = "Nintentdo (PUBLISHER)";
	const char *five = "Apple's Mac (CONSOLE)";
	const char *six = "Xbox 360 (CONSOLE) ";
	const char *seven = " ";
	const char *eight = " ";
	const char *nine = " ";
	const char *ten = " ";
	const char *eleven;
	const char *twelve;
	const char *thirteen;
	const char *fourteen;
	const char *fifteen;
	const char *sixteen;
	const char *seventeen;
	const char *eighteen;
	const char *nineteen;
	const char *twenty;

	// Listing items
	vector<string>list;
	list.push_back(one);
	list.push_back(two);
	list.push_back(three);
	list.push_back(four);
	list.push_back(five);
	list.push_back(six);
	list.push_back(seven);
	list.push_back(eight);
	list.push_back(nine);
	list.push_back(ten);

	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;

	string input;
	cout << "\t\t\tWelcome to Game Manager!\nGame Manager is a listing software that can only hold TWENTY ITEMS.\n";
	cout << "Here are the commands:\n";
	cout << " 'help' - Displays all possible commands again.\n";
	cout <<	" 'list' - Shows your list of Game Titles, Developers, Publishers, and Consoles.\n";
	cout <<	" 'replace' - Switches an item on the list with another of your choosing.\n";
	cout << " 'add' - Inserts a new item of your choosing.\n"; 
	cout << " 'remove' - Deletes an item of your choosing.\n";
	cout << " 'quit' - Exits the program.\n\n";
	
	cout << "Your games:\n";
	for(iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << " - " << *iter << endl;
	}
	cout << endl;

	while (input != "quit")
	{
		cout << "Please input something...\n";
		cin  >> input;

		// Help
		if (input == "help")
		{
			cout << "\n 'help' - Displays all possible commands again.\n";
			cout <<	" 'list' - Shows your list of game related items\n";
			cout <<	" 'replace' - Switches an item on the list with another of your choosing.\n";
			cout << " 'add' - Inserts a new item of your choosing.\n"; 
			cout << " 'remove' - Deletes an item of your choosing\n";
			cout << " 'quit' - Exits the program.\n\n";
		};

		// List
		if (input == "list")
		{
			cout << "\n Your games:\n";
			for(iter = list.begin(); iter != list.end(); ++iter)
			{
				cout << "  - " << *iter << endl;
			}
			cout << endl;
		};

		// Replace 
		if (input == "replace")
		{
			cout << "\n What item do you want to replace?";

			while ((input == "1") && (input == "2") && (input == "3"))
			{
				cout << "\n Select an item by it's number (1 - 20).";
				cin >> input;
	
				if (input == "1")
				{

				}
				else if (input == "2")
				{

				}
				else if (input == "3")
				{

				}
				else if (input == "4")
				{

				}
				else if (input == "5")
				{

				}
				else if (input == "6")
				{

				}
				else if (input == "7")
				{

				}
				else if (input == "8")
				{

				}
				else if (input == "9")
				{

				}
				else if (input == "10")
				{

				}
				else if (input == "11")
				{

				}
				else if (input == "12")
				{
	
				}
				else if (input == "13")
				{

				}
				else if (input == "14")
				{

				}
				else if (input == "15")
				{

				}
				else if (input == "16")
				{

				}
				else if (input == "17")
				{

				}
				else if (input == "18")
				{

				}
				else if (input == "19")
				{

				}
				else if (input == "20")
				{

				}
				else
				{

				}
			};

			cout << "\n You replaced 'Window's PC (CONSOLE)' with 'Apple's Mac (CONSOLE)'.\n\n";
			myIterator = list.begin();
			*myIterator = "Apple's Mac (CONSOLE)";
		};

		// Add
		if (input == "add")
		{
			cout << "\n You added 'Xbox 360 (CONSOLE)' to your list.\n\n";
			list.insert(list.end(), "Xbox 360 (CONSOLE)");
		};

		// Remove
		if (input == "remove")
		{
			cout << "\n You removed 'Sony (PUBLISHER)' from your list.\n\n";
			list.erase((list.begin() + 2));
		};

		// Unrecognized Input
		if ((input != "quit") && (input != "help") && (input != "list") && (input != "replace") && (input != "add") && (input != "remove"))
		{
			cout << "\n That is not a command... if you have forgotten the commands type 'help'.\n\n";
		};
	};

	cout << "\nThank you for using Game Manager! Have a nice day!\n";
}