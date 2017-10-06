#include <iostream>
using namespace std;

void printBaseTwo(int n){
    if (n != 0) {
        printBaseTwo(n/2);
        cout << n%2;
    }
}

int main(int arg, char*argc[])
{
    printBaseTwo(3);
    cout << endl;
    printBaseTwo(9);
    cout << endl;
    printBaseTwo(1076);
    cout << endl;
}
