#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void printAllSubsets ( int arr[], int n ) {
     ll sz = ( 1<<n );

     for ( ll bits = 0; bits < sz; bits++ ) { // the bits are set from 0000.. to 1111...
        for ( int j = 0; j < n; j++ ) {
            if ( bits & (1<<j) ) { // whent the bits is set
                 printf ( "%d ",arr[j]);
            }

        }
          printf("\n");
     }


}

int main() {
    int n;
    cin >> n;
    int nums[n];
    for ( int i=0; i<n; i++ ) {
        cin >> nums[i];
    }
    printAllSubsets(nums, n);
    return 0;

}
