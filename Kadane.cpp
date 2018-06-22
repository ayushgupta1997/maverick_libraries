/*Algo : Kadane
Problem : Maxcontiguous subarray sum
Paradigm : Dynamic Programming
Time Complexity : O(n)
*/

#include <bits/stdc++.h>

using namespace std;

int maxsubarraySum(int arr[], int n) { // this method will not work when all elements of array are negative
    int max_ending = 0, max_so_far = INT_MIN;
    for (int i = 0; i < n; i++) {
        max_ending += arr[i];
        if(max_ending < 0) {
            max_ending = 0;
        }
        else if(max_so_far < max_ending) {
            max_so_far = max_ending;
        }
    }
    return max_so_far;
}

int maxsubarraySum2(int arr[], int n) { //this method will when the array contains all elements as well in other cases too.
    int curr_max = arr[0];
    int max_so_far = arr[0];
    for (int i = 1; i<n; i++) {
        curr_max = max(arr[i], curr_max+arr[i]); // <------------This is important line
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main() {
    int arr[100],n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = maxsubarraySum(arr, n);
    int ans2 = maxsubarraySum2(arr, n);
    cout << ans << endl;
    cout << ans2;
    return 0;
}
