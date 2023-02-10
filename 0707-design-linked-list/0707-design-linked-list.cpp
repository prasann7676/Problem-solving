struct node{
    node(){
        val=0;
        next=NULL;
    }
    node(int x){
        val=x;
        next=NULL;
    }
    int val;
    node *next;
};
class MyLinkedList {
public:
    node *head;
    MyLinkedList() {
        head=NULL;
    }
    
    int get(int index) {
        int i=0;
        node *cur=head;
        while(cur){
            // cout<<cur->val<< "\n";
            if(i==index)
                return cur->val;
            cur = cur->next;
            i++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        node *newHead = new node(val);
        newHead->next = head;
        head = newHead;
    }
    
    void addAtTail(int val) {
        node *newTail = new node(val);
        node *cur = head;
        if(head==NULL){
            head = newTail;
            return;
        }
        while(cur->next)
            cur = cur->next;
        cout<<cur->val<< " "<<newTail->val<< '\n';
        cur->next = newTail;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        node *cur = head, *pre = NULL;
        int i=0;
        while(cur){
            if(i==index-1){
                pre=cur;
                break;
            }
            cur = cur->next;
            i++;
        }
        if(pre==NULL)
            return;
        node *newNode = new node(val);
        node *tmp = pre->next;
        pre->next = newNode;
        newNode->next = tmp;
    }
    
    void deleteAtIndex(int index) {
        if(head==NULL)
            return;
        if(index==0){
            head = head->next;
            return;
        }
        int i=0;
        node *cur = head, *pre = NULL;
        while(cur){
            if(i==index-1){
                pre = cur;
                cur = cur->next;
                break;
            }
            cur = cur->next;
            i++;
        }
        if(cur==NULL)
            return;
        pre->next = cur->next;
        delete(cur);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */