#include <iostream>
#define size 3
using namespace std;

#pragma region Structs
struct product {
	int quantity;
	double price;
	char name[30];

	double getTotalPrice() {
		return price * quantity;
	}

} pa = { 10, 109.99, "Thermal Paste" };

struct order {
	product p;
	int ordered;
};
#pragma endregion

#pragma region Declarations
void accessStructValues(product);
void pretendToChangeStructValue(int);
void actuallyChangingStructValue(int&);
void manipulateArray(product[], int);
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

	//other funny things
	//pb.name = "spdasdas"; wont work
	strcpy_s(pb.name, "New name with strcpy()");
	accessStructValues(pb);
	cout << strcmp("ola", "ola"); //if zero they are equal
	for (int i = 0; i < strlen(pb.name); i++)
		cout << "Character #" << i << ": " << pb.name[i] << endl;

	//nested struct
	order o = { pb, 3 }; 
	cout << "Ordered Quantity: " << o.ordered << endl;
	cout << "Product Ordered: " << o.p.name << endl;

	//reference as parameter
	pretendToChangeStructValue(pa.quantity);
	accessStructValues(pa);
	actuallyChangingStructValue(pa.quantity);
	accessStructValues(pa);

	//function as struct's property
	cout << "Total Price: $" << pa.getTotalPrice() << endl;

	//manipulating array of structs
	manipulateArray(products, size);

	return EXIT_SUCCESS; //coulde be EXIT_FAILURE
}

#pragma region Definitions
void accessStructValues(product p) {
	cout << "Name: " << p.name << " - Quantity: " << p.quantity << " - Price: $" << p.price << endl;
}

void pretendToChangeStructValue(int quantity) {
	quantity += 200;
}

void actuallyChangingStructValue(int& quantity) {
	quantity += 200;
}

void manipulateArray(product products[], int productsCount) {
	for (int i = 0; i < productsCount; i++) {
		products[i].price = 0.9999;
		accessStructValues(products[i]);
	}
}
#pragma endregion