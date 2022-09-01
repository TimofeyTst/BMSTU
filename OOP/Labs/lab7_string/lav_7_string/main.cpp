#include <iostream>

using namespace std;

class fruit_without
{
private:
	string name;
	float sod_c;
public:
	void init(string iname, float isod_c)
	{
		name = iname;
		sod_c = isod_c;
	}
	void print()
	{
		std::cout << name << " consist " << sod_c << " mg in 100g of vitamin C \nYou need to eat " << how_much_kg_c() << " kg Of this fruit per day";
	}
	float how_much_kg_c()
	{
		const float norma = 50;
		return norma / (sod_c) / 10;
	}
};
class fruit_with
{
private:
	string name;
	float sod_c;
public:
	fruit_with(string iname="None", float isod_c = 0)
	{
		name = iname;
		sod_c = isod_c;
	}
	void init(string iname, float isod_c)
	{
		name = iname;
		sod_c = isod_c;
	}
	void print()
	{
		std::cout << name << " consist " << sod_c << " mg in 100g of vitamin C \nYou need to eat " << how_much_kg_c() << " kg Of this fruit per day";
	}
	float how_much_kg_c()
	{
		const float norma = 50;
		return norma / (sod_c) / 10;
	}
};
fruit_without apple = {};
fruit_with banana("Banana", 12);
int main()
{
	string iname = "Apple";
	apple.init(iname, 10);
	apple.print();
	cout << "\n\n";
	banana.print();

	cout << endl;
	return 0;
}