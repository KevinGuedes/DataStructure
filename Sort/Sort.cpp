#include <iostream>
using namespace std;

void selection(int[], int);
void insertion(int[], int);
void bubble(int[], int);

int main()
{
	int data[3] = {3,2,1};
	insertion(data, 3);
}

void selection(int data[], int size) {
	int i, j, aux, temp;

	for (i = 0; i < size - 1; i++) {
		aux = i;

		for (j = i + 1; j < size; j++) {
			if (data[aux] > data[j]) {
				aux = j;
			}
		}

		temp = data[aux];
		data[aux] = data[i];
		data[i] = temp;
	}
}

void insertion(int vet[], int size)
{
	int j, i, aux;
	for (i = 1; i < size; i++)
	{
		aux = vet[i];

		for (j = i; j > 0 && aux < vet[j - 1]; j--)
			vet[j] = vet[j - 1];

		vet[j] = aux;
	}
}

void bubble(int data[], int size)
{
	int j, i, aux;

	for (i = 0; i < size - 1; i++)
		for (j = size - 1; j > i; j--)
			if (data[j] < data[j - 1])
			{
				aux = data[j];
				data[j] = data[j - 1];
				data[j - 1] = aux;
			}

	//not working
}

