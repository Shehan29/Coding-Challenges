#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Maximum Subarray
int maxSubArray(int n, int array[]) {
    int max = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += array[i];
        if (curr_sum < 0)
            curr_sum = 0;
        if (max < curr_sum)
            max = curr_sum;
    }
    return max;
}

int main (int arg, char*argc[])
{
    int array[5] = {100,-120,4,-3,4000};
    cout<<maxSubArray(5,array)<<endl;
}
