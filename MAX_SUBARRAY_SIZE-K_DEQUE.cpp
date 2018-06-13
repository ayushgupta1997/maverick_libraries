/*  Algo : Sliding Window
    DS  : Deque
    Time Comlexity : O(n)
    Problem : https://www.hackerrank.com/challenges/deque-stl/problem
 */

#include <bits/stdc++.h>

using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> dq;
    int i;
    vector<int> ans;
    for(i=0; i<k; i++) {
        while(!dq.empty() && arr[dq.back()]<=arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for ( ;i<n; i++) {
        ans.push_back(arr[dq.front()]);
        while(!dq.empty() && dq.front()<=i-k) {
            dq.pop_front();
        }
         while(!dq.empty() && arr[dq.back()]<=arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
     ans.push_back(arr[dq.front()]);
    for (auto x: ans) {
        cout << x <<" ";
    }
    printf("\n");
    
}

int main(){
  
	int t;
	cin >> t;  // number of test cases
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];    //input array
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
