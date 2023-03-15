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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
            return 1;
        queue<TreeNode *> q;
        int lev = 0;
        q.push(root);
        while(!q.empty()){
            int len = q.size(),cnt=0,isNull=0;
            for(int ite=1;ite<=len;ite++){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left){
                    if(isNull)
                        return 0;
                    q.push(cur->left); cnt++;
                    if(cur->right){
                        q.push(cur->right); cnt++;
                    }
                    else
                        isNull=1;
                }
                else{
                    isNull=1;
                    if(cur->right)
                        return 0;
                }
            }
            if(!q.empty()){
                long long level = (1LL<<lev);
                if(len != level)
                    return 0;
            }
            lev++;
        }
        return 1;
    }
};