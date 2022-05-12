#include <iostream>
#define realSize 3
using namespace std;

void insertNumber(int[], int&);
void showList(int[], int);
void showElementAt(int[], int);
int sequenceSearch(int, int[], int);
void removeElement(int, int[], int&);

int main()
{
	int currentSize = 2, data[realSize] = { 10, 20, NULL };
	showList(data, currentSize);

	insertNumber(data, currentSize);
	showList(data, currentSize);

	showElementAt(data, currentSize);

	int elementToBeRemoved;
	cout << "Which element you want to remove? ";
	cin >> elementToBeRemoved;
	cout << endl;
	removeElement(elementToBeRemoved, data, currentSize);

	insertNumber(data, currentSize);
	showList(data, currentSize);

	return EXIT_SUCCESS;
}

void insertNumber(int data[], int& currentSize) {

	if (realSize == currentSize)
		cout << "List is fully alocated" << endl;
	else {
		int newNumber;
		cout << "Type the number you want to enter: ";
		cin >> newNumber;
		cout << endl;
		data[currentSize] = newNumber;
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
		cout << endl << endl;

		if (index + 1 > currentSize)
			cout << "No element is alocated at index #" << index << endl;
		else
			cout << "Element at index #" << index << ": " << data[index] << endl;
	}
}

void removeElement(int element, int data[], int& currentSize) {
	int elementIndex = sequenceSearch(element, data, currentSize);

	if (elementIndex == -1)
		cout << "Empty list" << endl;
	else if (elementIndex == -2)
		cout << "Element not found" << endl;
	else {
		for (int i = elementIndex; i < currentSize - 1; i++)
			data[i] = data[i + 1];

		currentSize--;
		cout << endl;
		showList(data, currentSize);
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