#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
 
using namespace std;
 
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
 
 
int32_t main() {
    fastio;
 
    int n,k;

    cin>>n>>k;
    int org=k;
    k--;

//    cout<<n<<" "<<(k*(k+1))/2<<endl;
    
    if(n<=1) {
        cout<<-1<<endl;
    } else if(n<k) {
        cout<<1<<endl;
    } else if(n>(k*(k+1))/2){
        cout<<-1<<endl;
    } else {
        int ans=0;
        while(n>0) {
            n-=k;
            k--;
            ans++;
        }
        cout<<ans<<endl;
    }

}
