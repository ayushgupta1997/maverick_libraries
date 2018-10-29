/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : 
  Time Complexity = O(n2) reverse sorted(Worst Case), O(1)-already-sorted
  Inplace, Stable  = Yes
  
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
// main function
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
    for (int i = 0; i < n; i++) {
    	int swaps = 0;
    	for (int j = 1; j < n; j++) {
    		if(arr[j-1]>arr[j]) {
    			swap(arr[j-1], arr[j]);
    			swaps++;
    		}
    	}
    	if(swaps==0) {
    		break;
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << arr[i] << " ";
    }
    
	return 0;

}
