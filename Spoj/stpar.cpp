#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)

using namespace std;

map<int,int> mmap;

void printVector(vi a) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printArray(int a[], int n) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,n-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void solve() {

}
 
int32_t main() {
   fastio;

    float ans=0;

    // for(float i=2; i<10000; i++) {
    //     ans+=1/i;
    //     cout<<ans<<" ";        
    // }

    int t=10;
//    cin>>t;
 
    while(1) {

        stack<int> st;

        int n;
        cin>>n;
        vi vec;
        vi vec2;
        int temp;
        int fu=1;

        if(n==0) {
            break;
        }

        FORN(0,n-1) {
            cin>>temp;
            vec.push_back(temp);
        }

        int current=1;

        FORN(0,n-1) {
            if(vec[i]==current) {
                vec2.push_back(vec[i]);
                current++;
                while(!st.empty() && st.top()==current) {
                    int temp = st.top();
                    st.pop();
                    current++;
                    vec2.push_back(temp);
                }

            } else {
                st.push(vec[i]);
            }
        }

        if(st.empty()) {
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }

    }

    return 0;
}
