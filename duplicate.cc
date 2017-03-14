#include <vector>
#include <iostream>
using namespace std;

bool hasDuplicate(int a[], int size)
{
    int index, current;
    for (int i = 0; i < size; i++)
    {
        while (a[i] != i+1)        //check if value at a[i] is in the correct position
        {
            index = a[i]-1;        //index is position where it should go
            current = a[index];    //current value at index
            if (a[i] == current)
            {
                return true;       //duplicate if value appears in both places
            }
            else
            {
                a[index] = a[i];   //swap
                a[i] = current;
            }
        }
    }
    return false;
}

int main(int arg, char*argc[])
{
    int a[] = {3,4,1,2,5};
    int b[] = {3,2,1,2,5};
    int c[] = {1,2,3,4,5};
    int d[] = {};
    int e[] = {2,2,2};
    int f[] = {10,9,8,7,6,5,4,3,2,1};

    if (hasDuplicate(a, sizeof(a)/sizeof(a[0])))
        cout<<"a"<<endl;
    if (hasDuplicate(b,sizeof(b)/sizeof(b[0])))
        cout<<"b"<<endl;
    if (hasDuplicate(c, sizeof(c)/sizeof(c[0])))
        cout<<"c"<<endl;
    if (hasDuplicate(d, sizeof(d)/sizeof(d[0])))
        cout<<"d"<<endl;
    if (hasDuplicate(e, sizeof(e)/sizeof(e[0])))
        cout<<"e"<<endl;
    if (hasDuplicate(f, sizeof(f)/sizeof(f[0])))
        cout<<"f"<<endl;
}












