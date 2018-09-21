/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : [2018-09-21 17:36]
  Time Complexity : O(logn)
  In place sort ---"No as extra space is required"
  Stable : "Yes"	
  
 */

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define rep(i, a, b)             for(int i = a; i < b; i++)
#define REP(i, a, b)             for(int i = a; i <= b; i++)
#define sc(n)                    scanf("%d",&n)
#define sc2(a,b)                 scanf("%d%d", &a, &b) 
#define pb                       push_back
#define ff                       first
#define ss                       second
#define mp                       make_pair
#define mt                       make_tuple
#define SET(a, b)                memset(a,b,sizeof(a)) 
#define all(v)                   (v).begin(),(v).end()
#define rall(v)                  (v).rbegin(),(v),rend()
#define MAX 200005
#define MOD 1000000007

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef double ld;

void merge(int arr[], int l, int mid, int r) {
	int L[mid-l+1];
	int L_size = mid-l+1;
	int R_size = r-mid;
	int R[r-mid];
	int idx = 0;
	for (int i = l; i <= mid; i++) {
		L[idx++] = arr[i];
	}
	idx=0;
	for (int i = mid+1; i <= r; i++) {
		R[idx++] = arr[i];
	}
	// at this point we have the two subarrays left and right
	int i = 0, j = 0, k = l;
	while(i<L_size && j<R_size) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<L_size) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<R_size) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int l, int r) {
	if(l < r) {
		int mid = l+(r-l)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr, l, mid, r);
	}
}

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int arr[n];
    rep(i,0,n) {
    	cin >> arr[i];
    }
    mergesort(arr,0,n-1);
    rep(i,0,n) cout << arr[i] << " ";
	return 0;

}
