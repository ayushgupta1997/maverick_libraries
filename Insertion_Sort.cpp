/*  Algo : Insertion-Sort
    Inplace Sort : YES
    Stable Sort : YES
    Created on : 13/06/2018 by ayushgupta1997

    BEST CASE : when the array is almost sorted O(n)
    WORST CASE : when the array is reverse sorted O(n^2)
    Practical Application : In the sorting of playing-cards!

*/
#include <bits/stdc++.h>

using namespace std;


void printArr(int arr[], int n) {
    cout << "Array in sorted order is\n";
    for (int i=0; i<n; i++) {
        cout << arr[i]  << " ";
    }
}

void insertion_sort(int arr[], int n) {
    for ( int i=1; i<n; i++ ) {
        int j = i-1;
        int key = arr[i];
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    printArr(arr, n);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for ( int i=0; i<n; i++ ) {
        cin >> arr[i];
    }
    insertion_sort(arr,n);
    return 0;
}
