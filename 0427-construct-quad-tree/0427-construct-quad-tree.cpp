/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node *recurse(vector<vector<int>>& grid, int start_row, int end_row, int start_col, int end_col){
        if(end_row<start_row || end_col<start_col)
            return NULL;
        int flag=1, prev = grid[start_row][start_col];
        for(int i=start_row;i<=end_row;i++){
            for(int j=start_col;j<=end_col;j++){
                if(grid[i][j] != prev){
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            Node *root = new Node(prev,1);
            return root;
        }
        Node *root = new Node();
        int mid_row = start_row + (end_row-start_row)/2;
        int mid_col = start_col + (end_col-start_col)/2;
        root->isLeaf = 0;
        root->val = 1;
        root->topLeft = recurse(grid,start_row,mid_row,start_col,mid_col);
        root->topRight = recurse(grid,start_row,mid_row,mid_col+1,end_col);
        root->bottomLeft = recurse(grid,mid_row+1,end_row,start_col,mid_col);
        root->bottomRight = recurse(grid,mid_row+1,end_row,mid_col+1,end_col);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return recurse(grid,0,n-1,0,n-1);
    }
};