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

int caseNo=1;

void solve() {

    int N,K;
    cin>>N>>K;
    
    int temp;
    vi vec;
    int sum=0;

    FORN(0,K-1) {
        cin>>temp;
        vec.push_back(temp);
        sum+=temp;
    }

    if(sum<N) {
        cout<<"Scenario #"<<caseNo++<<": \n"<<"impossible\n\n";
    } else {
        sort(vec.begin(),vec.end());
        
        sum=0;
        int ind=K-1;
        int c=0;

        while(1) {
            sum+=vec[ind];
            c++;
            ind--;
            if(sum>=N) {
                break;
            }
        }
        cout<<"Scenario #"<<caseNo++<<": \n"<<c<<"\n\n";
    }



}
 
int32_t main() {
    
    fastio;

    int t=1;
    cin>>t;
 
    while(t--) {
        solve();
    }

    return 0;
}
