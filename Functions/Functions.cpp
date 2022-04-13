#include <iostream>
using namespace std;

#pragma region Declarations
void workingWithBasicFunctionAndVariables();
void changeGlobalVariableValue(void); //parameterless function, the void in bracketsis optional
void pretendToChangeValue(int, int); //function with two int parameters
void changeValue(int&, int&); //function that receives two references
int sumValues(int, int);
int g1, g2; //global variables

void workingWithArrays();
void modifyArray(double[], int);
void printArrayValues(double[], int);
#pragma endregion

int main()
{
    workingWithBasicFunctionAndVariables();
    cout << "\n\n";

    workingWithArrays();
    cout << "\n\n";


    int a, b;
    cout << "Tricky things using a and b as integers" << endl;
    a = 5;
    b = 3;
    int resultAsInt = a / b;
    float resultAsFloat = a / b;
    double resultAsDouble = a / b;
    cout << "Result as int of " << a << "/" << b << " = " << resultAsInt << endl;
    cout << "Result as float of " << a << "/" << b << " = " << resultAsFloat << endl;
    cout << "Result as double of " << a << "/" << b << " = " << resultAsDouble << endl;
    cout << "\n\n";

    float c, d;
    cout << "Tricky things using c and d as float" << endl;
    c = 5;
    d = 3;
    resultAsInt = c / d;
    resultAsFloat = c / d;
    resultAsDouble = c / d;
    cout << "Result as int of " << c << "/" << d << " = " << resultAsInt << endl;
    cout << "Result as float of " << c << "/" << c << " = " << resultAsFloat << endl;
    cout << "Result as double of " << c << "/" << d << " = " << resultAsDouble << endl;
    cout << "\n\n";

    int x = 3; int y = 2;
    cout << x / y;

    return EXIT_SUCCESS;
}

#pragma region Definitions
void workingWithBasicFunctionAndVariables() {
    g1 = 10;
    g2 = 20;
    cout << "Inital values of global variables" << endl;
    cout << "g1 = " << g1 << endl;
    cout << "g2 = " << g2 << endl;

    changeGlobalVariableValue();
    cout << "Global variables changed" << endl;
    cout << "g1 = " << g1 << endl;
    cout << "g2 = " << g2 << endl;

    int l1, l2; //local variables of the main() function
    cout << "l1: ";
    cin >> l1;
    cout << "l2: ";
    cin >> l2;

    pretendToChangeValue(l1, l2);
    cout << "Pretending to change values" << endl;
    cout << "l1 = " << l1 << endl;
    cout << "l2 = " << l2 << endl;

    changeValue(l1, l2);
    cout << "Actually changing values" << endl;
    cout << "l1 = " << l1 << endl;
    cout << "l2 = " << l2 << endl;

    int sum;
    sum = sumValues(l1, l2);
    cout << l1 << " + " << l2 << " = " << sum << endl;
}

void changeGlobalVariableValue(void) {
    g1 = 1;
    g2 = 2;
}

void pretendToChangeValue(int a, int b) {
    a = 5;
    b = 3;
}

void changeValue(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}

int sumValues(int a, int b) {
    return a + b;
}

void workingWithArrays() {
    const int size = 5;
    double values[size] = { 0, 1, 2, 3, 4 };

    cout << "Print array: " << values << ". It is the address" << endl;
    cout << "Array at index 0: " << values[0] << ". It is the actual value" << endl;

    cout << "Before modifications" << endl;
    printArrayValues(values, size);

    modifyArray(values, size); //they change like if it was a reference parameter

    cout << "After modifications" << endl;
    printArrayValues(values, size);
}

void modifyArray(double values[], int size) {
    for (int i = 0; i < size; i++)
        values[i] *= values[i];
}

void printArrayValues(double values[], int size) {
    for (int i = 0; i < size; i++)
        cout << "Value #" << i << " :" << values[i] << endl;
}
#pragma endregion
