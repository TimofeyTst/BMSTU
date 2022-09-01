#include <iostream>

using namespace std;

class fruit_without
{
private:
	char name[20];
	float sod_c;
public:
	void init(char iname[20], float isod_c)
	{
		*name = *iname;
		sod_c = isod_c;
	}
	void print()
	{
		cout << name[2] << endl;
		std::cout << *name << " consist " << sod_c << " mg in 100g of vitamin C \n You need to eat " << how_much_kg_c() << " Of this fruit per day";
	}
	float how_much_kg_c()
	{
		const float norma = 5;
		return norma / (sod_c) / 10;
	}
};
fruit_without apple={};
int main() 
{
	char iname[] = "apple";
	apple.init(iname, 10);
	apple.print();
	cout << endl;
	return 0;
}