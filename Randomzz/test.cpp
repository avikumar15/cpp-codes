#include<bits/stdc++.h>

using namespace std;
int cnt = 0;

void doIt(int s, vector<int> vec, int n,stack<int> st) {
    if(s==n) {
        cnt++;
        while(!st.empty()) {
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
        return;
    }

    //stack<int> backup = st;
    //cout<<vec[s]<<" ";
    st.push(vec[s]);
    doIt(s+1,vec,n,st);
    st.pop();
    doIt(s+1,vec,n,st);
}

int closedPath(int n) {
    int ans=0;

    while(n>0) {
        int d = n%10;
        n/=10;
        if(n==6 || n==4 || n==0 || n==9)
            ans++;
        else if(n==8)
            ans+=2;
    }
}

int main() {
    vector<int> vec = {1,2,3,4,5};
    int n = vec.size();
    stack<int> st;

    doIt(0,vec,n,st);
    cout<<endl<<cnt<<endl;
    return 0;
}
