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
//#define mp                       make_pair
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

vector<string> ans;

unordered_map<int, string> mp;

void solve(int num[], string temp, int index, int n) {
    if(index == n) {
        ans.push_back(temp);
        return;
    }
    else {
        int dig = num[index];
        for (int i = 0; i < mp[dig].size(); i++) {
            temp.push_back(mp[dig][i]);
            solve(num,temp,index+1,n);
            temp.pop_back();
        }
        return;
    }
}

int main() {
    int t;
    mp[2]="abc";
    mp[3]="def";
    mp[4]="ghi";
    mp[5]="jkl";
    mp[6]="mno";
    mp[7]="pqrs";
    mp[8]="tuv";
    mp[9]="wxyz";
    
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int num[n];
        rep(i,0,n) {
            cin >> num[i];
        }
        solve(num,"",0,n);
        for (auto x: ans) {
            cout << x << " ";
        }
        cout << endl;
        ans.clear();
    }
return 0;
}
