#pragma once
#include <iostream>
#include <vector>
#define n 10

using namespace std;
struct new_time
{
	string Theme, text;
};
class class_news
{
private:
	string Theme, text;
	bool read;
public:
	class_news(string iTheme = "None", string itext = "None", bool iread = false) 
	:Theme (iTheme), text (itext), read (iread) {}

	void reading()
	{
		if (read)
			cout << "\nAlready was written\n";
		else
		read = true;
	}
	void show()
	{
		cout << "===== " << Theme << " =====\n" << text << "\n";
		reading();
	}
	string get_Theme ()
	{
		return Theme;
	}
	string get_text()
	{
		return text;
	}
	bool is_read()
	{
		return read;
	}
};

class news_feed
{
public:
	vector<class_news> feed;
	news_feed() = default;
	news_feed(vector <new_time> inews_feed)
	{
		for (int i = 0; i < inews_feed.size(); i++)
		{
			feed.push_back(class_news(inews_feed[i].Theme, inews_feed[i].text));
		}
	}
	void show_all()
	{
		int i = 0;
		while (i < feed.size())
		{
			feed[i++].show();
			cout << endl;
		}
	}
	void add(new_time inews_time)
	{
		feed.push_back(class_news(inews_time.Theme, inews_time.text));
	}
	void mark_as_read(int num)
	{
		feed[num].reading();
	}
	void show_unread()
	{
		int i = 0;
		while (i < feed.size())
		{
			if (!feed[i].is_read())
			{
				feed[i].show();
				cout << endl;
			}
			i++;
		}
	}
	int count_news()
	{
		return feed.size();
	}

};