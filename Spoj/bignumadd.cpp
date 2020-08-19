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
            
        string str;
        cin>>str;

        if(str=="0") {
            break;
        }

        else{
            int dp[str.size()+5];

            dp[0]=1;
            dp[1]=1;
            if( (str[0]!='0' && str[0]<'2' && str[1]!='0') || (str[0]=='2' && str[1]<='6' && str[1]!='0' && str[0]!='0' )  ) {
                dp[1]++;
            }

            for(int i=2; i<str.size(); i++) {

                if((str[i]<='6' && str[i-1]=='2' || str[i-1]<'2' ) && str[i-1]!='0') {
                    if(str[i]=='0') {
                        dp[i]=dp[i-2];
                    } else {
                        dp[i]=dp[i-1]+dp[i-2];
                    }
                } else {
                    dp[i]=dp[i-1];
                }
            }

            cout<<dp[str.size()-1]<<endl;
        }

    }
    return 0;
}
