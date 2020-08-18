#include <iostream>
using namespace std;

void solve() {
    int n;
    int s;
    cin>>n>>s;
    int arr[n+5],p[n+5];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int ans=-1;
    int sum=0;
    int fx=-1,fy=-1;
    int mn=0;
    
    for(int i=0; i<n; i++) {
        int j=i;
        while(j<n && sum<s)
            sum+=arr[j++];
        while(sum>s) {
            sum-=arr[mn++];
        }
        
        if(sum==s) {
            fx=mn;
            fy=j;
            ans=1;
            break;
        } else {
            i=j-1;
        }
    }
    if(ans==-1)
        cout<<-1<<endl;
    else
        cout<<fx+1<<" "<<fy<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
        solve();
        
        
	return 0;
}
