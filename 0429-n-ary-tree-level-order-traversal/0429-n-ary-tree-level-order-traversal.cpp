/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> res;
            for(int ite=1;ite<=len;ite++){
                auto cur = q.front();
                res.push_back(cur->val);
                q.pop();
                for(auto i:cur->children)
                    q.push(i);
            }
            ans.push_back(res);
        }
        return ans;
    }
};