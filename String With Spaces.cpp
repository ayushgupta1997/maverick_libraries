/*cpp program to print all possible solutions of string with one space*/
#include <bits/stdc++.h>

using namespace std;

void recur(string str, char buff[], int i, int j, int n) {
    if(i == n) {
        buff[j] = '\0';
        cout << buff << endl;
        return;
    }
    buff[j] = str[i];
    recur(str,buff,i+1,j+1,n);
    buff[j] = ' ';
    buff[j+1] = str[i];
    recur(str, buff, i+1, j+2,n);
}
void printpattern(string s) {
    int n = s.length();
    char buff[2*n];
    buff[0] = s[0];
    recur(s,buff,1,1,n);
}
int main() {
    string s;
    cin >> s;
    printpattern(s);
    return 0;
}
