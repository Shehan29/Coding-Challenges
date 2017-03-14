#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int profit(int a[], int n)
{
    int min = a[0];
    int maxProfit = -32767;
    int current;
    for (int i = 1; i < n; i++)
    {
        current = a[i] - min;
        if (current > maxProfit)
            maxProfit = current;
        if (a[i] < min)
            min = a[i];
    }
    return maxProfit;
}

int main(int arg, char*argc[])
{
    int a[] = {7,4,12,14,1,6};
    int b[] = {7,6,1};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    cout<<profit(a, n)<<endl;
    cout<<profit(b, m)<<endl;;
}
