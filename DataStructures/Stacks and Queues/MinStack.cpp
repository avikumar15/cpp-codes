#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> st;
    int topp;
    int mn;
    
    MinStack() {
        topp=-1;
        mn=-1;
    }
    
    void push(int x) {
        if(topp==-1) {
            mn=x;
        }
        mn=min(mn,x);
        st.push_back(x);
        st.push_back(mn);
        topp++;
        topp++;
    }
    
    void pop() {
        if(topp==-1) {
            return;
        }
        st.pop_back();
        st.pop_back();
        topp--;
        topp--;
        if(topp>=0)
            mn=st[topp];
    }
    
    int top() {
        if(topp==-1)
            return -1;
        return st[topp-1];
    }
    
    int getMin() {
        if(topp==-1)
            return -1;
        
        return st[topp];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */