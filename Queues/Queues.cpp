#include <iostream>
#define size 3
using namespace std;

struct queue {
	int data[size];
	int start, end, currentSize;
};

void enqueue(queue&, int);
void dequeue(queue&);
int getFirstElement(queue);
bool isFull(queue);
bool isEmpty(queue);

int main()
{
	queue queue{ {}, 0, 0, 0 };
	enqueue(queue, 999);
	enqueue(queue, 1000);
	enqueue(queue, 3333);
	dequeue(queue);
	enqueue(queue, 4444);

	dequeue(queue);
	cout << "The first element is: " << getFirstElement(queue) << endl;

	dequeue(queue);
	dequeue(queue);
}

void enqueue(queue& queue, int newData) {
	if (isFull(queue))
		cout << "Failed to enqueue data" << endl;
	else {
		queue.data[queue.end] = newData;
		queue.end++;
		queue.currentSize++;

		if (queue.end == size) queue.end = 0;

		cout << "Data enqueued successfully" << endl;
	}
}

void dequeue(queue& queue) {
	if (isEmpty(queue))
		cout << "Failed to dequeue data" << endl;
	else {
		cout << "Removing: " << queue.data[queue.start] << endl;
		queue.currentSize--;
		queue.start++; //Not actually replacing the data just changing the start
		if (queue.start == size) queue.start = 0;
	}
}

int getFirstElement(queue queue)
{
	if (isEmpty(queue))
		cout << "Failed to retrieve first element data" << endl;
	else return queue.data[queue.start];
}

bool isFull(queue queue) {
	if (queue.currentSize == size) {
		cout << "Queue is full" << endl;
		return true;
	}
	else return false;
}

bool isEmpty(queue queue) {
	if (queue.currentSize == 0) {
		cout << "Queue is empty" << endl;
		return true;
	}
	else return false;
}
