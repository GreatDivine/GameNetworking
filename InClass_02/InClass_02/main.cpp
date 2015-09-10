#include <fstream>

struct Data
{
	int key;
	double value;
};

int main()
{
	Data d;
	d.key = 103;
	d.value = 1509.456;

	std::fstream myFile("data.bin", std::ios::out | std::ios::binary);
	myFile.write((char*)&d, sizeof(Data));
	myFile.close();

	Data d2;

	myFile.open("data.bin", std::ios::in | std::ios::binary);
	myFile.read((char*)&d2, sizeof(Data));
	myFile.close();

	printf("The data is, %i, %f\n"
		, d2.key
		, d2.value);

	system("pause");

	return 0;
}