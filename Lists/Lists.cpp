#include <iostream>
#define realSize 3
using namespace std;

#include <iostream>

void insertNumberAt(int, int[], int&);
void showList(int[], int);
void showElementAt(int[], int);
int sequenceSearch(int, int[], int);
void removeElement(int, int[], int);

int main()
{
	int currentSize = 2, data[realSize] = { 10, 20, NULL };
	insertNumberAt(2, data, currentSize);
	showElementAt(data, 2);
	removeElement(20, data, currentSize);

	return EXIT_SUCCESS;
}

void insertNumberAt(int index, int data[], int& currentSize) {

	if (realSize == currentSize)
		cout << "List is fully alocated" << endl;
	else {
		int newNumber;
		cout << "Type the number you want to enter at index #" << index << ": ";
		cin >> newNumber;
		cout << endl;
		data[index] = newNumber;
		showList(data, currentSize);
		currentSize++;
	}

}

void showElementAt(int data[], int currentSize) {
	if (currentSize == 0)
		cout << "Empty list";
	else {
		cout << "Type the index of the element you want: ";
		int index;
		cin >> index;
		cout << endl;

		if (index + 1 > currentSize)
			cout << "No element is alocated at index #" << index << endl;
		else
			cout << "Element at index #" << index << ": " << data[index] << endl;
	}
}

void removeElement(int element, int data[], int size) {
	int elementIndex = sequenceSearch(element, data, size);

	if (elementIndex == -1)
		cout << "Empty list" << endl;
	else if (elementIndex == -2)
		cout << "Element not found" << endl;
	else {
		for (int i = elementIndex; i < size - 1; i++)
			data[i] = data[i + 1];

		showList(data, size);
	}
}


int sequenceSearch(int element, int data[], int currentSize) {
	if (currentSize == 0)
		return -1;

	for (int i = 0; i < currentSize; i++)
		if (data[i] == element)
			return i;

	return -2;
}

void showList(int data[], int currentSize) {
	if (currentSize == 0)
		cout << "Empty list";
	else {
		for (int i = 0; i < currentSize; i++)
			cout << "Element #" << i << ": " << data[i] << endl;

		cout << endl;
	}
}