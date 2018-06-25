/*Problem Statement :
Implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible,
and interprets them as a numerical value.The string can contain additional characters after those that form the integral number,
which are ignored and have no effect on the behavior of this function.If the first sequence of non-whitespace characters in str is 
not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters,
no conversion is performed.If no valid conversion could be performed, a zero value is returned.
Note:
-->Only the space character ' ' is considered as whitespace character.
-->Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
*/

#include <bits/stdc++.h>
using namespace std;
int myatoi(string str) {
    if(str.size() == 0) {
            return 0;
    }
        int id = 0;
        while(str[id] == ' ') {
            id++;
        }
        if(id == str.size()) {
            return 0;
        }
        long long sign = 1;
        if(str[id] == '-') {
            sign = -1;
            id++;
        }
        else if(str[id] == '+') {
            sign = 1;
            id++;
        }
        if(str[id]>='0' && str[id]<='9') {
            long long res=0;
            for( ;str[id]>='0' && str[id]<='9'; id++) {
                res = res*10 + (long long)(str[id]-'0');
               if(res*sign > INT_MAX) {
                  return INT_MAX;
               }
               else if(res*sign < INT_MIN) {
                return INT_MIN;
               }
            }
            return res*sign;
        }
        else {
            return 0;
        }
}
int main() {
    string str;
    cin >> str;
    cout << myatoi(str);
    return 0;
}
