//Reference : https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int id[100];

int root(int x) {
	while(x!=id[x]) {
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void union1(int x, int y) {
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

void kruskal(vector<pair<int,pair<int,int>>> v) {
	int n = v.size();
	for (int i=0; i<n; i++) {
		int x = v[i].second.first;
		int y = v[i].second.second;
		int w = v[i].first;
		if(root(x)!=root(y)) {
			ans += w;
			union1(x,y);
		}
	}
}
int main() {
	int n,e;

	cin >> n >> e;
	for (int i=0; i<=99; i++) {
		id[i] = i;
	}	

	vector<pair<int, pair<int,int>>> v;
	for( int i = 0; i < e; i++) {
		int x,y,w;
		cin >> x >> y >> w;
		v.push_back(make_pair(w, make_pair(x,y)));
	}
	sort(v.begin(), v.end());
	kruskal(v);
	cout << ans << endl;
}
