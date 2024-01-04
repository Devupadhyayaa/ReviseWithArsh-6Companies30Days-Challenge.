int sum;
vector<int>solve(TreeNode* node){
    if(node==NULL){
        vector<int>temp(3);
        temp[1]=INT_MIN;
        temp[2]=INT_MAX;
        return temp;
    }
    vector<int>lft=solve(node->left);
    vector<int>rt=solve(node->right);
    int x=node->val;
    if(lft[1]<x&&rt[2]>x){
        int ans=lft[0]+rt[0]+x;
        sum=max(sum,ans);
        return {ans,max(rt[1],x),min(lft[2],x)};
    }
    return {max(lft[0],rt[0]),INT_MAX,INT_MIN};
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        sum=0;
        solve(root);
        if(sum<0)return 0;
        return sum;
    }
};
