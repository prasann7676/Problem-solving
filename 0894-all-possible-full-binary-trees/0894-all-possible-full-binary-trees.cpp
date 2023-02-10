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
    void inorder(TreeNode *head){
        if(head==NULL)
            return;
        inorder(head->left);
        cout<<head->val<< " ";
        inorder(head->right);
    }
    vector<TreeNode *> recurse(int n){
        vector<TreeNode *> res;
        if(n==1){
            res.push_back(new TreeNode(0));
            return res;
        }
        for(int i=1;i<n;i+=2){
            auto left = recurse(i);
            auto right = recurse(n-i-1);
            for(int l=0;l<(int)left.size();l++){
                for(int r=0;r<(int)right.size();r++){
                    TreeNode *root = new TreeNode(0);
                    root->left = left[l];
                    root->right = right[r];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)
            return {};
        return recurse(n);
    }
};