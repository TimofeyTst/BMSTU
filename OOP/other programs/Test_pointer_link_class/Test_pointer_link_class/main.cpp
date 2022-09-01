#include <iostream>
using namespace std;

class A
{
private:
	int num;
public:
	A(int inum = 0): num(inum) {};
	~A() {};

};

class B
{
private:
	double num;
	string name;
public:
	B() :B(0,"free") { cout << "Constructor B() \n"; };
	B(double inum, string iname) :num(inum), name(iname) { cout << "Conscructor B(int, string)\n"; };
	~B() { "Desctructor B\n"; };

	void print() { cout << "\nName: " << name << "\tNumber: " << num <<"\n"; }

	B* ptr_ptr(B* VCPointer)
	{
		cout << "==========B* ptr_ptr (B* VCPointer)==========\n" << "VCPointer Before: " << VCPointer->num << "\tVCPointer After: ";
		VCPointer->num = -1.2;
		cout << VCPointer->num;
		cout << endl;
		return VCPointer;
	}
	B* ptr_link(B& VCLink)
	{
		cout << "==========B* ptr_link(B& VCLink)==========\n" << "VCLink Before: " << VCLink.num << "\tVCLink After: ";
		VCLink.num = -2.2;
		cout << VCLink.num;
		cout << endl;
		return &VCLink;
	}
	B& link_ptr(B* VCPointer)
	{
		cout << "==========B& link_ptr(B* VCPointer)==========\n" << "VCPointer Before: " << VCPointer->num << "\tVCPointer After: ";
		VCPointer->num = -3.2;
		cout << VCPointer->num;
		cout << endl;
		return *VCPointer;
	}
	B& link_link(B& VCLink)
	{
		cout << "==========B& link_link(B& VCLink)==========\n" << "VCLink Before: " << VCLink.num << "\tVCLink After: ";
		VCLink.num = -4.2;
		cout << VCLink.num;
		cout << endl;
		return VCLink;
	}
};


int main()
{
	B obj1(1.5,"object 1"), obj2(2.5,"object 2"), free;
	cout << "========== ========== ==========\n";
	obj1.print();
	obj2.print();
	free.print();

	free = obj1.link_link(obj2);//.
	obj1.print();
	obj2.print();
	free.print();

	free = obj1.link_ptr(&obj2);//.
	obj1.print();
	obj2.print();
	free.print();

	free = *obj1.ptr_link(obj2);//->
	obj1.print();
	obj2.print();
	free.print();

	free = *obj1.ptr_ptr(&obj2);//->
	obj1.print();
	obj2.print();
	free.print();

	cout << "-------> In cunclision I can say that all changes in syntaxes\n";
	return 0;
}