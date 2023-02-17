/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *recurse(int l, int r, unordered_map<int,int> &mp){
        if(l>r)
            return NULL;
        if(l==r){
            TreeNode *root = new TreeNode(mp[l]);
            return root;
        }
        int mid = (l+r)/2;
        TreeNode *root = new TreeNode(mp[mid]);
        root->left = recurse(l,mid-1,mp);
        root->right = recurse(mid+1,r,mp);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode *cur = head;
        int ind = 0;
        while(cur){
            mp[ind++]=cur->val;
            cur = cur->next;
        }
        return recurse(0,ind-1,mp);
    }
};