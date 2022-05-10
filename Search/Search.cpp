#include <iostream>
using namespace std;

bool sequenceSearch(int, int[], int);
bool binarySearch(int, int[], int);

int main()
{
	int data[3] = { 3,2,1 };
	bool result = sequenceSearch(4, data, 3);
	cout << result << endl;

	result = binarySearch(4, data, 3);
	cout << result << endl;
}

bool sequenceSearch(int element, int data[], int size) {
	bool elementExists = false;

	for(int i = 0; i < size && !elementExists; i++)
		if (data[i] == element)
			elementExists = true;

	return elementExists;
}

bool binarySearch(int element, int data[], int size) {
	int init = 0, end = size - 1;
	int middle = (init + end) / 2;

	while (element != data[middle] && init != end) {
		if (element > data[middle])
			init = middle + 1;
		else
			end = middle;

		middle = (init + end) / 2;
	}

	return data[middle] == element;
}
