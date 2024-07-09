/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node, Node *&ans, vector<Node *> &vis){
        vis[node->val]=ans;
        for(auto i: node->neighbors){
            if(vis[i->val]){
                ans->neighbors.push_back(vis[i->val]);
                continue;
            }
            Node *tmp = new Node(i->val);
            ans->neighbors.push_back(tmp);
            dfs(i, tmp, vis);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        Node* ans = new Node(1);
        const int sz = 101;
        vector<Node *> vis(sz,NULL);
        dfs(node, ans, vis); 
        return ans;
    }
};