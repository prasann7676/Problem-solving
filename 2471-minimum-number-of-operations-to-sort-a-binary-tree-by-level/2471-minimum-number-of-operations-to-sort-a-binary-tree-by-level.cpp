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
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size(),ind=0,h[100005]={0};
            vector<int> res;
            for(int num=1;num<=n;num++){
                TreeNode *cur = q.front();
                q.pop();   
                res.push_back(cur->val);
                h[cur->val] = ind++;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            vector<int> tmp = res;
            sort(tmp.begin(),tmp.end());
            for(int i=0;i<(int)tmp.size();i++){
                if(res[i] != tmp[i]){
                    ans++;
                    h[res[i]]=h[tmp[i]];
                    swap(res[i],res[h[tmp[i]]]);
                }
            }
        }
        return ans;
    }
};