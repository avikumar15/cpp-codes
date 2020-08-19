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
 
    int t=10;
//    cin>>t;
 
    while(1) {
            
        int n;
        string s;
        string ans="";

        cin>>n;

        if(n==0) {
            break;
        }

        cin>>s;

        int r=s.size()/n;

        for(int i=0; i<n; i++) {
            int temp=i;
            int p=0;
            while(temp<s.size()) {
                p++;
                ans+=s[temp];
                if(p%2==1)
                temp+=2*(n-i)-1;
                else 
                temp+=(2*i+1);
            }
        }

        cout<<ans<<endl;

    }
    return 0;
}
