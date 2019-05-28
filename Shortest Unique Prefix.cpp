struct TrieNode {
  int freq;
  struct TrieNode* child[26];
};

vector<string> ans;

struct TrieNode* newTrieNode() {
    TrieNode* nn = new TrieNode;
    nn->freq = 1;
    for (int i = 0; i < 26; i++) {
        nn->child[i] = NULL;
    }
    return nn;
}

void insert(TrieNode* root, string A) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < A.size(); i++) {
        int id = A[i]-97;
        if(pCrawl->child[id]!=NULL) {
            (pCrawl->child[id]->freq)++;
        }
        else {
            pCrawl->child[id] = newTrieNode();
        }
        pCrawl = pCrawl->child[id];
    }
}

string findPrefix(TrieNode* root, string pre) {
   string ans;
   TrieNode* curr = root;
   if(pre.size()==0) 
        return ans;
   int i = 0;
   do{
       curr = curr->child[pre[i]-97];
       ans += pre[i];
       i++;
   } while(i<pre.size() && curr->freq != 1);
   return ans;
}

vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    ans.clear();
    TrieNode* root = newTrieNode();
    root ->freq = 0;
    for (int i = 0; i < n; i++) {
        insert(root, A[i]);
    } 
    for (int i = 0; i < n; i++) {
        ans.push_back(findPrefix(root, A[i]));
    }
    return ans;    
}
