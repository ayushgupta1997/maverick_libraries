#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define REP(i,a,b) for(int i=a; i<=b; i++)

const int S = (1<<21);

int main() {
    
    vector<int> primes(S,1);
    vector<int> primeval;
    primes[1]=0;
    for (int i = 2; i < S; i++) {
        if(!primes[i]) {
            continue;
        }
        primeval.push_back(i);
        for ( int j = i+i; j < S; j+=i) {
            primes[j] = 0;
        }
    }
  
    return 0;
}


