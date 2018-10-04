/*

  author      : (Ayush Gupta @ayushgupta1997)
  Modified On : [2018-10-04 10:21]	
  
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

struct trieNode {
	trieNode *child[26];
	int cnt;
	bool eow;
};

trieNode* getNode() {
	trieNode *node = new trieNode;
	for (int i = 0; i <26; i++) {
		node->child[i] = nullptr;
	}
	node->cnt = 0;
	node->eow =false;
	return node;
}

void insert(trieNode *node, string key) {
	int l = key.length();
	trieNode *crawl = node;
	for (int i = 0; i < l; i++) {
		int idx = key[i]-'a';
		if(crawl->child[idx] == nullptr) {
			crawl->child[idx] = getNode();
		}
		crawl = crawl->child[idx];
		(crawl->cnt)++;
	}
	crawl->eow = true;
}

int find(trieNode *node, string key) {
	int l = key.length();
	trieNode *crawl = node;
	for (int i = 0; i < l; i++) {
		int idx = key[i]-'a';
		if(crawl->child[idx] == nullptr) {
			return 0;
		}
		crawl = crawl->child[idx];

	}
	return crawl->cnt;
}

int main()  {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    string op,key;
    trieNode *root = new trieNode;
    while(t--) {
    	cin >> op >> key;
    	if(op == "add") {
    		insert(root, key);
    	}
    	else if(op == "find") {
    		cout << find(root, key) << endl;
    	}
    }
	return 0;

}

//Sample Problem : https://www.hackerrank.com/challenges/contacts/submissions/code/43919410
