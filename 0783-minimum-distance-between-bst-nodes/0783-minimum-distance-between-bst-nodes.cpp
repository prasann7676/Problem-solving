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
    void recurse(TreeNode *root, int &ans, int &pre){
        if(root==NULL)
            return;
        recurse(root->left,ans,pre);
        ans = min(ans,abs(root->val-pre));
        pre = root->val;
        recurse(root->right,ans,pre);
    }
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX, pre = INT_MAX;
        recurse(root,ans,pre);
        return ans;
    }
};