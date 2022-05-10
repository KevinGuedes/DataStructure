#include <iostream>
using namespace std;

int main()
{
    char c1[6] = "kevin";
    char c2[10] = "auidsudi";
    strcpy_s(c1, c2);
    cout << c2 << endl;
    cout << "Hello World!" << endl;
}
