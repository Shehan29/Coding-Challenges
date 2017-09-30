#include <iostream>
using namespace std;

void printPermutations(string word, string current, int size) {
    if (current.length() == size) {
        cout << current << endl;
        return;
    }
    int length = word.length();
    for (int i = 0; i < length; i++) {
        printPermutations(word.substr(0,i)+word.substr(i+1, length-i-1), current + word[i], size);
    }
}

void printAll(string word) {
    for (int i = 0; i < word.length(); i++) {
        printPermutations(word, "", i+1);
    }
}

int main(int arg, char*argc[])
{
    string word = "abcd";
    printAll(word);
}
