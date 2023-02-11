class CustomStack {
public:
    int maxSize;
    stack<int> st;
    vector<int> inc;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        inc.resize(maxSize,0);
    }
    
    void push(int x) {
        if((int)st.size()<maxSize)
            st.push(x);
    }
    
    int pop() {
        if(st.empty())
            return -1;
        int sz = (int)st.size();
        if(sz==1){
            int ans = st.top() + inc[sz-1];
            st.pop();
            inc[sz-1]=0;
            return ans;
        }
        else{
            int ans = st.top() + inc[sz-1];
            st.pop();
            inc[sz-2] += inc[sz-1];
            inc[sz-1]=0;
            return ans;
        }
    }
    
    void increment(int k, int val) {
        int ind = min(k-1,(int)st.size()-1);
        if(ind>=0)
            inc[ind] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */