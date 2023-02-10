struct node{
    node(int x){
        val = x;
        next = NULL;
        down = NULL;
    }
    node(int x, node *next, node *down){
        val = x;
        this->next = next;
        this->down = down;
    }
    int val;
    node *next, *down;
};
class Skiplist {
public:
    node *head;
    Skiplist() {
        head = new node(-1);
    }
    
    bool search(int target) {
        node *cur = head;
        while(cur){
            while(cur->next && cur->next->val<target)
                cur = cur->next;
            if(cur->next && cur->next->val==target)
                return 1;
            cur = cur->down;
        }
        return 0;
    }
    
    void add(int num) {
        stack<node *> st;
        node *cur = head;
        while(cur){
            while(cur->next && cur->next->val<num)
                cur = cur->next;
            st.push(cur);
            cur = cur->down;
        }
        int insert = 1;
        node *down = NULL;
        while(insert && !st.empty()){
            node *cur = st.top();
            st.pop();
            cur->next = new node(num,cur->next,down);
            down = cur->next;
            insert = rand()%2;
        }
        if(insert)
            head = new node(-1,NULL,head);
    }
    
    bool erase(int num) {
        node *cur = head;
        int f = 0;
        while(cur){
            while(cur->next && cur->next->val < num) {
                cur = cur->next;
            }
            if (cur->next && cur->next->val == num) {
                f = 1;
                cur->next = cur->next->next;
            }
            cur = cur->down;
        }
        return f;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */