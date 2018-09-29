/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : 
  
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

vector<int> g[MAX];
int par[MAX];
int depth[MAX];

void dfs(int v, int p, int d) {
  depth[v] = d;
  par[v] = p;
  for(int c: g[v])
    if(c != p) dfs(c, v, d + 1);
}

vector<int> getpath(int a, int b) {
  vector<int> ans, path1, path2;
  path1.push_back(a);
  path2.push_back(b);
  while(a != b) {
    if(depth[a] < depth[b]) path2.push_back(b = par[b]);
    else if(depth[a] > depth[b]) path1.push_back(a = par[a]);
    else if(depth[a] == depth[b]) path1.push_back(a = par[a]), path2.push_back(b = par[b]);
  }
  reverse(path2.begin(), path2.end());
  path2.erase(path2.begin());
  path1.insert(path1.end(), path2.begin(), path2.end());
  return ans = path1;
}

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,u,v;
    cin >> n;
    int arr[n+1], ans[n+1];
    REP(i,1,n) {
      cin >> arr[i];
    }
    rep(i,0,n-1) {
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    dfs(1, -1, 0);    // 1
   
    for (int i = 1; i <= n; i++) {
      ans[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           if(i!=j) {
              vector<int> temp = getpath(i,j);
              // for (auto x: temp) {
              //   cout << x << " ";
              // }
             // cout << endl;
              int gg = __gcd(arr[i], arr[j]);
              for (auto x: temp) {
                 if(x!=i && x!=j) {
                     ans[x] = max(ans[x], gg);
                 }
              }

           }

       }
    }
    REP(i,1,n) {
      cout << ans[i] << " ";
    }
    
  return 0;

}



