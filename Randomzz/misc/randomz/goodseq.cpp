#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
 
using namespace std;

vi primeNum;

void SieveOfEratosthenes(int n) {

    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
       primeNum.push_back(p);
} 

void solve() {

    int n;
    cin>>n;
    vi vec;
    int temp;

    FORN(1,n) {
        cin>>temp;
        vec.push_back(temp);
    }

    // sort(vec.begin(),vec.end());
    
    int last=vec[0];
    vi dp(n+5,0);
    int ans=1;

    FORN(1,n-1) {
        if(__gcd(last,vec[i])!=1) {
            ans++;
            last=vec[i];
        } else {
            if(ans==1)
            last=vec[i];
            continue;
        }
    }

    cout<<ans<<endl;

}
 
int32_t main() {
//    fastio;
    SieveOfEratosthenes(pow(10,5)+5);
    for(int i=0; i<primeNum.size(); i++) {
        cout<<primeNum[i]<<" ";
    }
    cout<<endl;

    int t=1;
//    cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}
