#include <iostream>
#define size 3
using namespace std;

#pragma region Structs
struct product {
	int quantity;
	float price;
	char name[30];
} pa = { 10, 109.99, "Thermal Paste" };

struct order {
	product p;
	int ordered;
};
#pragma endregion

#pragma region Declarations
void accessStructValues(product);

#pragma endregion

int main()
{
	product pb = { 90, 1.50, "Pencil" };
	product pc = { 1, 34.65, "Clean Code Book" };

	product products[size] = { pa, pb, pc };

	for (int i = 0; i < size; i++) {
		cout << "Current Name: " << products[i].name << endl;
		cout << "New Name: "; cin.getline(products[i].name, 30);
		cout << "New Name Length: " << strlen(products[i].name) << endl;
		accessStructValues(products[i]);
		cout << "\n\n";
	}

	//pb.name = "spdasdas"; wont work
	strcpy_s(pb.name, "New name with strcpy()");
	accessStructValues(pb);
	cout << strcmp("ola", "ola"); //if zero they are equal


	for (int i = 0; i < strlen(pb.name); i++)
		cout << "Character #" << i << ": " << pb.name[i] << endl;


	order o = { pb, 3 };
	cout << "Ordered Quantity: " << o.ordered << endl;
	cout << "Product Ordered: " << o.p.name << endl;


	return EXIT_SUCCESS; //coulde be EXIT_FAILURE
}

#pragma region Definitions
void accessStructValues(product p) {
	cout << "Name: " << p.name << " - Quantity: " << p.quantity << " - Price: $" << p.price << endl;
}
#pragma endregion