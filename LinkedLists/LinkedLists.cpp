#include <iostream>
using namespace std;

struct element {
	int data;
	element* next;
};

void showElementData(element*);
element* insertAtStart(element*, int);


int main()
{
	element* el1 = new element;
	el1->data = 3;
	el1->next = NULL;

	//Insertion ate the end of the list
	el1->next = new element;
	el1->next->data = 4;
	el1->next->next = NULL;


	delete el1;
	cout << "After delete: " << el1 << endl;
	el1 = 0;
	cout << "After equal to 0: " << el1 << endl;



	element* list = NULL;
	list = insertAtStart(list, 999);


	return EXIT_SUCCESS;
}

void showElementData(element* el) {
	cout << "Element data: " << el->data << endl;
}

element* insertAtStart(element* list, int data) {
	element* temp = new element;
	temp->data = data;
	temp->next = list;

	return temp;
}

