#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
// #define cout cout<<setprecision(15)
 
using namespace std;


void solve() {

    string str;
    cin>>str;

    vi part;
    int n=str.size();

    vi oneP(n+5),oneS(n+5),zeroP(n+5),zeroS(n+5);
    
    if(str[0]=='0') {
        oneP[0]=0;
        zeroP[0]=1;
    } else {
        oneP[0]=1;
        zeroP[0]=0;
    }

    if(str[n-1]=='0') {
        oneS[n-1]=0;
        zeroS[n-1]=1;
    } else {
        oneS[n-1]=1;
        zeroS[n-1]=0;
    }
    

    for(int i=1; i<n; i++) {
        oneP[i]=oneP[i-1];
        zeroP[i]=zeroP[i-1];
        if(str[i]=='1') 
            oneP[i]++;
        else 
            zeroP[i]++;
    }

    for(int i=n-2; i>=0; i--) {
        oneS[i]=oneS[i+1];
        zeroS[i]=zeroS[i+1];
        if(str[i]=='1') 
            oneS[i]++;
        else 
            zeroS[i]++;
    }

    int fu=-1;
    int ans=LONG_LONG_MAX;

    // 110011011110100111
    // 012345678901234567

    for(int i=1; i<n; i++) {
        if(str[i]!=str[i-1]) {
            fu+=1;
            // cout<<zeroP[i]<<" "<<zeroS[i]<<" "<<oneP[i]<<" "<<oneS[i]<<endl;
            if(str[i]=='0'){
                ans=min({ans, oneP[i]+oneS[i] , (zeroP[i]+zeroS[i]-1), (oneP[i]+zeroS[i]), (zeroP[i-1]+oneS[i]) });
                // cout<<oneP[i]+oneS[i]<<" "<<zeroP[i]+zeroS[i]-1<<" "<<oneP[i]+zeroS[i]<<" "<<oneS[i]<<endl;
            }
            else
            ans=min({ans, zeroP[i]+zeroS[i] , (oneP[i]+oneS[i]-1), (oneP[i-1]+zeroS[i]), (zeroP[i]+oneS[i]) });

            int j=i;

            while(str[j+1]==str[j] && j<n) {
                j++;
            }
            i=j;

            if(str[i]=='0') 
                ans=min(ans,oneP[j]+zeroS[j]-1);
            else 
                ans=min(ans,zeroP[j]+oneS[j]-1);

            // cout<<"we are at "<<i<<" and ans is "<<ans<<endl;
            // if(str[i]=='0')
            // ans=min({ans,min(oneP[i-1],oneS[i+1]),min(zeroP[i],zeroS[i])});
            // else 
            // ans=min({ans,min(zeroP[i-1],zeroS[i+1]), min(oneP[i],oneS[i])});
        }
    }

    if(fu==-1 || fu==0)
    cout<<0<<endl;
    else
    cout<<ans<<endl;

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
