#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//Most Frequent Substring
string maxSubString(string s, int size, int n) {
    unordered_map<string, int> subFreq;
    int max = 0;
    string maxSub = "";
    for (int i = 0; i < n-size+1; i++) {
        subFreq[s.substr(i,size)]++;
        if (subFreq[s.substr(i,size)] > max) {
            max = subFreq[s.substr(i,size)];
            maxSub = s.substr(i,size);
        }
    }
    cout<<max<<endl;
    return maxSub;
}


int main(int arg, char*argc[])
{
    string s = "abcdabcd";
    int n = s.length();
    int size = 8;
    
    string sub = maxSubString(s, size, n);
    cout<<sub<<endl;
}
