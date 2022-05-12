#include <iostream>
#define size 3
using namespace std;

void push(int[], int&, int);
void pop(int[], int&, int&);
int top(int[], int);
void showStack(int[], int);
bool isFull(int);
bool isEmpty(int);


int main()
{
	int stack[size], topElementIndex = -1, lastPoppedElement;
	pop(stack, topElementIndex, lastPoppedElement);

	push(stack, topElementIndex, 333);
	showStack(stack, topElementIndex);


	push(stack, topElementIndex, 222);
	showStack(stack, topElementIndex);

	push(stack, topElementIndex, 111);
	showStack(stack, topElementIndex);

	push(stack, topElementIndex, 111);
	cout << "Top element: " << top(stack, topElementIndex) << endl;
}

void showStack(int stack[], int topElementIndex) {
	if (isEmpty(topElementIndex))
		cout << "Failed to show stack" << endl;
	else {
		cout << "Current stack data: " << endl;
		for (int i = topElementIndex; i > -1; i--)
			cout << "Element #" << i << ": " << stack[i] << endl;
		cout << endl;
	}
}

void push(int stack[], int& topElementIndex, int element) {
	if (isFull(topElementIndex))
		cout << "Failed to add element to the stack" << endl;
	else {
		topElementIndex++;
		stack[topElementIndex] = element;
	}
}

void pop(int stack[], int& topElementIndex, int& lastPoppedElement) {
	if (isEmpty(topElementIndex))
		cout << "Failed to remove element from the stack" << endl;
	else {
		lastPoppedElement = stack[topElementIndex]; //
		topElementIndex--; //The element is not removed, but the top index is updated
	}
}

int top(int stack[], int topElementIndex) {
	if (isEmpty(topElementIndex))
		cout << "Failed to retrieve element from the stack" << endl;
	else return stack[topElementIndex];
}

bool isFull(int topElementIndex) {
	if (topElementIndex == size - 1) {
		cout << "Stack is full" << endl;
		return true;
	}
	else return false;
}

bool isEmpty(int topElementIndex) {
	if (topElementIndex == -1) {
		cout << "Stack is empty" << endl;
		return true;
	}
	else return false;
}

