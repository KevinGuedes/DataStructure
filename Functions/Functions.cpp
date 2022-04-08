#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

void changeGlobalVariableValue(void); //parameterless function, the void in bracketsis optional
void pretendToChangeValue(int, int); //function with two int parameters
void changeValue(int&, int&); //function that receives two references
int sumValues(int, int);
int g1, g2; //global variables

int main()
{
    changeGlobalVariableValue();
    cout << "n1 = " << g1 << endl;
    cout << "n2 = " << g2 << endl;

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

void changeGlobalVariableValue(void){
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