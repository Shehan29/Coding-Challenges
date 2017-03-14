#include <iostream>
#include <string>
using namespace std;

void balanced(string s)
{
    int extraBrace = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
            extraBrace++;
        else if (s[i] == '}')
            extraBrace--;
        if (extraBrace < 0)
        {
            cout<<"unbalanced"<<endl;
            return;
        }
    }
    if (extraBrace == 0)
        cout<<"balanced"<<endl;
    else
        cout<<"unbalanced"<<endl;
}

int main(int arg, char*argc[])
{
    string s = "{{}}{}";    //balanced
    string t = "{{{}}";     //unbalanced
    string u = "{ }{ } }";  //unbalanced
    string v = "}{";        //unbalanced
    string w = "{ }}{{ }";  //unbalanced
    
    balanced(s);
    balanced(t);
    balanced(u);
    balanced(v);
    balanced(w);
}
