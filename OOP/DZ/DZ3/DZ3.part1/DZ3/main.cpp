#include <iostream>
#include "classes.h"
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
	news_feed News_feed; //Class

	new_time Inew_feed; //struct //C:\Users\yarik\Desktop\Standard\BMSTU\2 sem\OOP\DZ\DZ3\DZ3
	fstream file; string name = "C:\\Users\\yarik\\Desktop\\Standard\\BMSTU\\2 sem\\OOP\\DZ\\DZ3\\DZ3.part1\\Times.txt";
	file.open(name, fstream::in);
	
	if (!file.is_open())
		cout << "File doesn`t exist. Name: " << name;
	else
	{
		while (!file.eof())
		{
			getline(file, Inew_feed.Theme);
			getline(file, Inew_feed.text);
			News_feed.add(Inew_feed);
		}
		cout << "Enter to read the feed\n";
		if (_getch() == '\r')
		{
			News_feed.show_all();
			cout << "-> It is end of feed\n";
		}
		Inew_feed = { "Visual Studio","Today visual studio have been updated\nAll changes you can see in our documents" };
		News_feed.add(Inew_feed);
		//Unread
		cout << "--> Enter to see unread messages\n";
		if (_getch() == '\r')
		{
			cout << "#UNREAD messages:" << endl;
			News_feed.show_unread();
		}
	}
	system("Pause");
	return 0;
}