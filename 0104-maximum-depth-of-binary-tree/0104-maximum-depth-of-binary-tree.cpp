/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recurse(TreeNode * root,int cur, int &ans){
        if(root==NULL){
            ans = max(ans,cur);
            return;
        }
        recurse(root->left,cur+1,ans);
        recurse(root->right,cur+1,ans);
    }
    
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0,cur=0;
        recurse(root,cur,ans);
        return ans;
    }
};