#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	  #endif*/
	cin >> n;
	int a[100005],b;
	int pos, inv = 0;
	int k=1;
	int arr[n+1][n+1];
	for ( int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 0) {
            pos = i;
			}
		}
	}
	for ( int i = 1; i <= n; i++) {
		for ( int j = 1; j <= n; j++) {
			if(arr[i][j]!= 0)
                a[k++]=arr[i][j];
		}
	}

	for ( int i = 1; i < k; i++) {
		for (int j = i+1; j < k; j++) {
			if(a[i]>a[j]) {
				inv++;
			}
		}
	}

	if((n%2 == 1) && (inv)%2 == 0) {
		cout << "YES\n";
	}
  
	else if(n%2 == 0) {
		if(((n-pos+1)%2 == 1) && inv%2 == 0) {
			cout << "YES\n";
		}
		else if((n-pos+1)%2 == 0 && (inv%2) == 1) {
			cout << "YES\n";
		}
		else
        cout << "NO\n";

	}
	else
			cout << "NO\n";
	return 0;
}
