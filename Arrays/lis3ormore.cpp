// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

vector<int> find3Numbers(vector<int>, int);

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        auto res = find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}// } Driver Code Ends


/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> arr, int N) {
    vector<int> ans;
    int n=N;
    int mnl[N+5],mxr[N+5];
    
    for(int i=0; i<n; i++) 
        mnl[i]=-1, mxr[i]=-1;
        
    mnl[0]=arr[0];
    mxr[n-1]=arr[n-1];
    for(int i=1; i<n; i++) {
        mnl[i]=min(mnl[i-1],arr[i]);
    }
    
    for(int i=n-2; i>=0; i--) {
        mxr[i]=max(mxr[i+1],arr[i]);
    }
    
    int a=-1,b=-1,c=-1;
    
    for(int i=1; i<n-1; i++) {
        if(mnl[i]<arr[i] && arr[i]<mxr[i]) {
            a=mnl[i];
            b=arr[i];
            c=mxr[i];
        }
    }
    
    if(a!=-1)
    ans.push_back(a),
    ans.push_back(b),
    ans.push_back(c);
    
    return ans;
}