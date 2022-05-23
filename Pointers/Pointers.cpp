#include <iostream>
using namespace std;

struct product {
	float price;
	char name[30];
};

void showProductData(product*);

int main()
{
	int count = 3;
	int* ptrCount = &count;
	cout << "Value: " << count << endl;
	cout << "Address: " << &count << endl;
	cout << "Pointer data: " << ptrCount << endl;
	cout << "Pointer address: " << &ptrCount << endl;

	cout << "Data from the address pointed by the pointer: " << *ptrCount << endl;

	product p1 = { 10.99, "Hammer" };
	product* ptrP1 = &p1;
	cout << "Product name: " << ptrP1->name << endl;
	cout << "Product name: " << (*ptrP1).name << endl;
	showProductData(ptrP1);


	return EXIT_SUCCESS;
}

void showProductData(product* m) {
	cout << "Product name: " << m->name << endl;
	cout << "Product price: $" << (*m).price << endl;


}


