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
    void zigzag(TreeNode *root, vector<vector<int>> &ans){
        if(root==NULL)
            return;
        queue<TreeNode *> q; q.push(root);
        int cur_lev=0;
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;
            for(int i=0;i<n;i++){
                TreeNode *cur = q.front(); q.pop();
                tmp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(cur_lev%2)
                reverse(tmp.begin(),tmp.end());
            cur_lev++;
            ans.push_back(tmp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        zigzag(root,ans);
        return ans;
    }
};