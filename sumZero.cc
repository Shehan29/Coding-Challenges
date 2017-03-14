#include <vector>
#include <iostream>
using namespace std;

void printList(vector<int>v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void sumZero(int current, int sum, int n, vector<int>v)
{
    if (current > n+1)
        return;
    else if (sum == 0)
        printList(v);
    else
    {
        v.push_back(current);
        sumZero(current+1, sum+current, n, v);
        v.pop_back();
        v.push_back(-current);
        sumZero(current+1, sum-current, n, v);
    }
}

int main(int arg, char*argc[])
{
    int N = 7;
    vector<int>solution = {1};
    sumZero(2, 1, N, solution);
}
