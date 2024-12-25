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
#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    void getSum(TreeNode *root, int &sum){
        if(root==NULL)
            return;
        sum += root->val;
        getSum(root->left,sum);
        getSum(root->right,sum);
    }
    
    int dfs(TreeNode *root, int sum, ll &ans){
        if(root==NULL)
            return 0;
        ll sumLeft=dfs(root->left,sum,ans);
        ll sumRight=dfs(root->right,sum,ans);
        int totSum = root->val + sumLeft+sumRight;
        ll tmpAns = max(sumLeft*(sum-sumLeft), sumRight*(sum-sumRight));
        ans = max(ans,tmpAns);
        return totSum;
    }
    int maxProduct(TreeNode* root) {
        int sum = 0;
        ll ans=0;
        getSum(root, sum);
        dfs(root, sum, ans);
        ans = ans%mod;
        return ans;
    }
};