#include <iostream>
#include <string>
#include <fstream>

//struct METRO
//{
//	unsigned int id, year, life;
//	std::string model;
//};

int main()
{
	//std::fstream File;
	//std::string file_name = "MetroDataBase.txt";

	//METRO var = {105,2017,10,"TESLA"}, var2;

	//File.open(file_name, std::fstream::app);
	//if (File.is_open())
	//{

	//	File.write((char*)&var, sizeof(METRO));
	//	File.close();
	//}
	//else {
	//	std::cout << "File wasnt open";
	//}
	//std::ifstream file2; file2.open(file_name);
	//file2.read((char*)&var2, sizeof(METRO));
	//std::cout << var.id << " " << var2.id << std::endl;
	//std::cout << var.year << " " << var2.year << std::endl;
	//std::cout << var.model << " " << var2.model << std::endl;
	//std::cout << var.life << " " << var2.life << std::endl;
	//file2.close();

	class abc {
	public:
		int num;
		abc() : abc(0) {};
		abc(int a) :num(a) {};
		void print() { std::cout << num << std::endl; };
	};
	abc A = '2';
	abc B(8);
	abc C;

	A.print();
	B.print();
	C.print();

	return 0;
}