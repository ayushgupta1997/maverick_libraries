/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(map<TreeNode*, TreeNode*> &mp,  TreeNode* node, TreeNode* parent) {
        if(node == NULL) 
          return;
        mp[node] = parent;
        solve(mp,node->left, node);
        solve(mp,node->right, node);
    }
    
    vector<int> distanceK (TreeNode* root, TreeNode* target, int K) {
       map<TreeNode*, TreeNode*> mp;
       solve(mp,root, NULL);                                          // this will create parent pointers to each node acts as undirected edges
       queue<TreeNode*> q;
       q.push(target);
       set<TreeNode*> seen;                                          // works similar as the visited[] array 
       seen.insert(target);
        int level = 0;
        vector<int> ans;
        while(!q.empty()) {
            if(level==K) {                                          // at  this point all the nodes are at the kth level        
                while(!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            int n = q.size();
            for (int i = 0; i < n; i++) {                            
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && seen.find(curr->left)==seen.end()) {
                    q.push(curr->left);
                    seen.insert(curr->left);
                }
                if(curr->right && seen.find(curr->right)==seen.end()) {
                    q.push(curr->right);
                    seen.insert(curr->right);
                }
                TreeNode* par = mp[curr];
                if(par!=NULL && seen.find(par)==seen.end()) {
                     q.push(par);
                    seen.insert(par);
                }
            }
            level++;        
        }
        return ans;
        
    }
};
