/*algo : merge sort
  paradigm : divide and conquer
  Time Complexity : O(nlg(n))
  In place sort : NO
  Stable  : YES
*/

#include <bits/stdc++.h>
using  namespace std;

void mergearr(int arr[], int l, int m, int r) {

    int n1 = (m-l+1); // size of first half of array
    int n2 = (r-m);   // size of second half of array
    int L[m-l+1];     // temporary first half array
    int R[r-m];       // temporary second half of array

    //storing both left and right halves before merging
    for (int i=0; i<m-l+1; i++) {
        L[i] = arr[l+i];
    }
    for (int j=0; j<r-m; j++) {
        R[j] = arr[m+1+j];
    }

    //Ready to merge :
    int i=0;
    int j=0;
    int k = l;  // initial value of index from where actual merge to be started


   //below all common elements in ascending order are there
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //Remaining elements left of first half of array
    while(i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    //Remaining elements of second half of array
    while(j<n2) {
        arr[k] = R[j];
        j++;
        k++;
    }


}

void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        mergearr(arr,l,m,r);
    }

}
void printArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin  >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
}
