#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void guess(int lower, int upper)
{
    int guess = ((upper-lower)/2) + lower;
    string response = "n";
    
    string shift;
    while (response != "y")
    {
        cout<<"Is your number "<<guess<<"? ";
        cin>>response;
        if (response == "y")
            break;
        cout<<"Is your number more or less? ";
        cin>>shift;
        if (upper == lower)
        {
            cout<<"You're messing with me!"<<endl;
            break;
        }
        if (shift == "l")
        {
            upper = guess-1;
            guess = ((upper-lower)/2) + lower;
        }
        else
        {
            lower = guess+1;
            guess = ((upper-lower)/2) + lower;
        }
        
    }
    cout<<"I'm a genius"<<endl;
}


int main(int arg, char*argc[])
{
    guess(1, 100);
}











