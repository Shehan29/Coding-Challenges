#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sumPair(int sum, vector<int>v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<"done"<<endl;
    int i = 0;
    int j = v.size() - 1;
    int currentSum = 0;
    while (i < j)
    {
        currentSum = v[i] + v[j];
        if (currentSum == sum)
        {
            cout<<v[i]<<", "<<v[j]<<endl;
            i++;
            j--;
        }
        else if (currentSum > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

int main(int arg, char*argc[])
{
    int array[] = {2,3,1,5,4,6,9,11,13,7};
    vector<int> myvector(array, array+(sizeof(array)/sizeof(array[0])));
    int sum = 7;
    sumPair(sum, myvector);
}
