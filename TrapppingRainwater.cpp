/*problem : trapping of rainwater
  Extra space of : O(n)
  Can we do better? Yes, by maintaing left and right pointer and updating left and right in seperate conditions:

*/

#include <bits/stdc++.h>

using namespace std;

#define sc(x) scanf("%d",&x)

int main() {
    int n;
    sc(n);
    int arr[n], left[n], right[n];

    for (int i = 0; i < n; i++) {
        sc(arr[i]);
    }

    left[0] = arr[0];

    for (int i = 1; i < n; i++) {
        left[i] = max(left[i-1], arr[i]);
    }

    right[n-1] = arr[n-1];

    for (int i = n-2; i >= 0; i--) {
        right[i] = max(right[i+1], arr[i]);
    }

    int volume = 0;

    for (int i = 0; i < n; i++) {
        volume += min(left[i], right[i]) - arr[i];
    }
    cout << volume;
    return 0;
}
