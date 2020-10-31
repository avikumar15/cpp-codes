// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
"baa", "abcd"
*/

void dfs(stack<char> &st, char ch, unordered_map<char,set<char>> mmap, unordered_map<char,bool> &vis ) {
    // if(vis[ch])
    //     return;
        
    vis[ch]=true;
    for(auto it=mmap[ch].begin(); it!=mmap[ch].end(); it++) {
        if(!vis[*it])
        dfs(st,*it,mmap,vis);
    }
    st.push(ch);
}

string findOrder(string dict[], int N, int K) {
    
    int n=N;
    int k=K;
    string res="";
    unordered_map<char,set<char>> mmap;
    unordered_map<char,bool> vis;
    int fu=1;
    
    for(int i=0; i<n-1; i++) {
        
        // int mx=max(dict[i].size(),dict[i+1].size());
        int mn=min(dict[i].size(),dict[i+1].size());
        
        for(int j=0; j<mn; j++) {
            if(dict[i][j]!=dict[i+1][j]) {
                // if(mmap[dict[i][j+1]].count(dict[i][j+1])>0) {
                //     fu=0;
                //     break;
                // }
                mmap[dict[i][j]].insert(dict[i][j+1]);
                vis[dict[i][j]]=false;
                vis[dict[i][j+1]]=false;
                
                break;
            }
        }
        
        // if(fu==0) {
        //     break;
        // }
        
    }
    
    stack<char> st;
    
    for(auto i:vis) {
        char s=i.first;
        if(!vis[s]) {
            dfs(st,s,mmap,vis);
        }
        //break;
    }
    
    while(!st.empty()) {
        char t=st.top();
        res+=t;
    }
    
    cout<<res<<endl;
    
    return res;
    
    
}
