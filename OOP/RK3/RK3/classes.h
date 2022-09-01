#pragma once
#include <iostream>

class A
{
public:
	float D[10];
	A(float iD[10])
	{
		for (int i = 0; i < 10; i++)
		{
			D[i] = iD[i];
		}
	}
	A()
	{
		for (int i = 0; i < 10; i++)
		{
			D[i] = 0;
		}
	}
	virtual void Out() = 0;
	void Print()
	{
		Out();
	}
};
class B : public A
{
public:
	B(float iD[10]) : A(iD) {};
	B() : A() {};
	void Out() override
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << D[i] << " ";
		}
	}
};
class C : public A
{
public:
	C(float iD[10]) : A(iD) {};
	C() : A() {};
	void Out() override
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << D[i] << "\n";
		}
	}
};

