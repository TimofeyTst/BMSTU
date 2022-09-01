#include "class.h"
#include <iostream>
using namespace std;

//class student
//{
//public:
//	student* prev, * next; //Если поставить private, то нельзя будет обратиться к cur->next в контейнере
////prev на самом деле по факту передает следующий элемент, надо поменять местами
//protected:
//	string name;
//	float scholarship_$;
//	float total_$;
//	bool is_live;
//	virtual int get_money()
//	{
//		if (is_live)
//		{
//			total_$ += scholarship_$;
//			return 1;
//		}
//		else return 0;
//	};
//	student(string iname, float ischolarship_$, float itotal_$) : name(iname), scholarship_$(ischolarship_$), total_$(itotal_$)
//	{
//		prev = next = nullptr;
//		if (iname != "NO NAME")
//			is_live = true;
//		else is_live = false;
//	};
//	student() : student("NO NAME", 0, 0) {};
//public:
//	virtual ~student() { cout << "\nvirtual ~student()\n"; };
//};
//
//class student_mgtu final: public student 
//{
//	float investments;
//	student_mgtu(string iname, float ischolarship_$, float itotal_$, float iinvestments) : student(iname, ischolarship_$, itotal_$)
//	{
//		investments = iinvestments;
//	};
//	student_mgtu() :student_mgtu("NO NAME", 0, 0, 0) {};
//	int get_money() override
//	{
//		if (is_live)
//		{
//			total_$ += scholarship_$ + investments*total_$;
//			return 1;
//		}
//		else return 0;
//	};
//	void print()
//	{
//		if (is_live)
//			cout << "Name: " << name << "\t with % investments " << investments << " and " << scholarship_$ << "$ scholarship\nTotal have: " << total_$ << "$";
//		else cout << "Person have died or not exist";
//	};
//	~student_mgtu() override { cout << "\nvirtual ~student_mgtu()\n"; }; 
//};
//
//class student_stgau final : public student
//{
//	float live_in_kife;
//	student_stgau(string iname, float ischolarship_$, float itotal_$, float ilive_in_kife) : student(iname, ischolarship_$, itotal_$)
//	{
//		live_in_kife = ilive_in_kife;
//	};
//	student_stgau() :student_stgau("NO NAME", 0, 0, 0) {};
//	int get_money() override
//	{
//		if (is_live)
//		{
//			total_$ += scholarship_$ - live_in_kife;
//			return 1;
//		}
//		else return 0;
//	};
//	void print()
//	{
//		if (is_live)
//			cout << "Name: " << name << "\t with spending on fucking beer or girls " << live_in_kife << "$ and " << scholarship_$ << "$ scholarship\nTotal have: " << total_$ << "$";
//		else cout << "Person have died or not exist";
//	};
//	~student_stgau() override { cout << "\nvirtual ~student_stgau()\n"; };
//};
//
//
////Begins something IMPORTANT
//class company_students
//{
//public:
//	student* first, * last, * cur; //Если объявить private, то нельзя first->next = fam; в 115 строчке
//public:
//	company_students() 
//	{
//		first = last = cur = nullptr;
//	};
//	~company_students() 
//	{ 
//		cout << "\n~company_students()\n"; 
//		student* work = last; cur = last;
//		while (cur != nullptr)
//		{
//			cur = work->prev;
//			delete (work);
//			work = cur;
//		}
//	};
//	void addte(student* fam)
//	{
//		if (first == nullptr)
//			first = last = fam;
//		else
//		{
//			fam->prev = first;
//			first->next = fam;
//		}
//	};
//	void delfe()
//	{
//		student* work=last;
//		if ((last = last->next) == nullptr)
//		{
//			first = last = cur = nullptr;
//			delete (work);
//		}
//		else
//		{
//			last->prev = nullptr;
//			delete (work);
//		};
//	};
//	void foreach(void (*func)(student* fam))
//	{
//		cur = first;
//		while (cur != nullptr)
//		{
//			(*func)(cur);
//			cur = cur->prev;
//		}
//	};
//	student* first()
//	{
//		return cur = first;
//	};
//	student* last()
//	{
//		return cur = last;
//	};
//	student* next()
//	{
//		return cur = cur->next;
//	};
//	student* prev()
//	{
//		return cur = cur->prev;
//	};
//};
//Ends

//Test programm in other file