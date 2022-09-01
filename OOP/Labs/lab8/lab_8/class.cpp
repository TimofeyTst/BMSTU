#include <iostream>
#include "class.h"
//using namespace std;
//const int today_year = 2022;
//struct date
//{
//	int day, month, year;
//};
//class human
//{
//protected:
//	string first_name, second_name, last_name;
//public:
//	date birthday;
//	human(string ifirst_name, string isecond_name, string ilast_name,date ibirthday): first_name (ifirst_name), second_name (isecond_name), 
//		last_name (ilast_name)
//	{
//		birthday.day = ibirthday.day; 
//		birthday.month = ibirthday.month;
//		birthday.year = ibirthday.year;
//	};
//	human() :human("none", "none", "none", { 0, 0, 0 }) {};
//	int how_old()
//	{
//		return today_year - birthday.year;
//	};
//	void print()
//	{
//		cout << "Name: " << first_name << ' ' << second_name << ' ' << last_name << "\tBirthday: "
//			<< birthday.day << '/' << birthday.month << '/' << birthday.year << "\t" << how_old() << " Years old";
//	}
//}; 
//class driver final : public human
//{
//protected:
//	date driver_license;
//	driver(string ifirst_name, string isecond_name, string ilast_name, date ibirthday, date idriver_license): 
//		human(ifirst_name, isecond_name, ilast_name, ibirthday)
//	{
//		driver_license = idriver_license;
//	};
//	driver(): driver ("none", "none", "none", { 0, 0, 0 }, { 0, 0, 0 }) {};
//	int stazh()
//	{
//		return today_year - driver_license.year;
//	};
//	int how_old_was_driver()
//	{
//		return driver_license.year - birthday.year;
//	};
//	void print()
//	{
//		cout << "Name: " << first_name << ' ' << second_name << ' ' << last_name << "\tBirthday: "
//			<< birthday.day << '/' << birthday.month << '/' << birthday.year << "\t" << how_old() << " Years old\n"
//			<< "Driver license from: " << driver_license.day << '/' << driver_license.month << '/' << driver_license.year << "\tWere received in " 
//			<< how_old_was_driver() << " years" << "\nStazh right now: " << stazh() << " years";
//	};
//};