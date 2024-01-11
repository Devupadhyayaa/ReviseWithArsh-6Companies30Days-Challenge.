/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
void solve(TreeNode* root, vector<vector<int>>& adj) {
    if (root != nullptr) {
        int idx = root->val;
        if (root->left != nullptr) {
            int lft = root->left->val;
            adj[idx - 1].push_back(lft - 1);
            adj[lft - 1].push_back(idx - 1);
            solve(root->left, adj);
        }
        if (root->right != nullptr) {
            int rt = root->right->val;
            adj[idx - 1].push_back(rt - 1);
            adj[rt - 1].push_back(idx - 1);
            solve(root->right, adj);
        }
    }
    return;
}
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(100005);
        solve(root, adj);
        queue<pair<int,int>>q;
        q.push({start-1,0});
        vector<int>vis(100005,-1);
        vis[start-1]=0;
        int time=0;
        while(!q.empty()){
            int node = q.front().first;
            time = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(vis[it]==-1){
                    q.push({it,time+1});
                    vis[it]=1;
                }
            }
        }
        return time;
    }
};
