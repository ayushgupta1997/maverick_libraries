/*Har Har Mahadev!
   *author      : Ayush Gupta
   *Modified On : 
[2019-08-22 12:10]  
https://www.codechef.com/problems/KNODES
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
#define MAX 100005
#define MOD 1000000007
#define INF 1000000005
#define bitcount(n) __builtin_popcountll(n)
#define M_H priority_queue<ll, vector<ll>, greater<ll>>

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef double ld;

int depth[MAX];
int start[MAX];
int endTime[MAX];
int timer;
int pa[MAX][20];
int LN = 20;
int n;

void dfs(int node, int parent, int curr_depth, vector<int> g[]) {
    timer++;
    start[node] = timer;
    pa[node][0] = parent;
    depth[node] = curr_depth;
    for (int i = 0; i < g[node].size(); i++)  {
        if(g[node][i]!=parent) {
            dfs(g[node][i], node, curr_depth+1, g);
        }
    }
    endTime[node] = timer;
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u]-depth[v];
    for (int i=0; i<LN; i++) {
        if((diff>>i)&1) {
            u = pa[u][i];
        }
    }
    if(u == v) return u;
    for (int i=LN-1; i>=0; i--) {
        if(pa[u][i] != pa[v][i]) {
            u = pa[u][i];
            v = pa[v][i];
        }
    }
    return pa[u][0];
}

int solve(vector<int> &nodes, vector<int> g[]) {
    int low_depth = nodes[0];
    int high_depth = nodes[0];

    int next = -1;
    for (int i=1; i< nodes.size(); i++) {
        if(depth[nodes[i]] < depth[low_depth]) {
            low_depth = nodes[i];
        }
        if(depth[nodes[i]] > depth[high_depth]) {
            high_depth = nodes[i];
        }
    } 

    for (int i = 0; i < nodes.size(); i++) {
        if(start[nodes[i]] <= start[high_depth] && endTime[nodes[i]]>=endTime[high_depth]) {
            nodes[i] = -1;
        }
        else if(next==-1 || depth[nodes[i]]>depth[next]) {
            next = nodes[i];
        }
    }
    if(next == -1) return 1;
    for (int i = 0; i < nodes.size(); i++) {
        if(nodes[i] == -1) continue;
       if(start[nodes[i]] <= start[next] && endTime[nodes[i]]>=endTime[next]) {
            nodes[i] = -1;
        }
        else return 0;
    }
    int lca = LCA(next, high_depth);
    return start[lca]<=start[low_depth] && endTime[lca]>=endTime[low_depth];

} 

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> g[n+1];
        rep(i,0,n-1) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        for (int j = 1; j < LN; j++) {
            for (int i = 1; i <= n; i++) {
                pa[i][j] = -1;
            }
        }
        timer = 0;
        dfs(1,-1,0, g);

        // preprocessing of the lca
        for (int j = 1; j < LN; j++) {
            for (int i = 1; i <= n; i++) {
                if(pa[i][j-1] != -1) {
                    pa[i][j] = pa[pa[i][j-1]][j-1];
                }
            }
        }
        int q;
        cin >> q;
        while(q--) {
            int k;
            cin >> k;
            vector<int> nodes;
            for (int i=0; i<k; i++) {
                int x;
                cin >> x;
                nodes.pb(x);
            }
            if(solve(nodes, g)) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }

    #ifndef ONLINE_JUDGE
      cerr<< "\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " seconds\n";
      #endif
    
    return 0;

}
