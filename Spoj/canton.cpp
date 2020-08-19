#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
#define cout std::cout

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

    int n;
    cin>>n;

    int f=1,s=1;
    int fans=1,sans=1;
    int inp=n;

    if(n==1) {
        
    } else if(n==2) {
        s=2;
        sans=2;
    } else if(n==3) {
        f=2;
        s=1;
        fans=f;
        sans=1;    
    }else {
        
        f=1;
        s=2;
        n-=2;

        int fend=3;
        int yep=3;

        int ncopy=n;

        while(n>0) {

            if(f!=fend) {
                if(fend!=1)
                f++;
                else 
                f--;
            } else {
                f--;

                if(fend!=1)
                fend=1;
                else {   
                    fend=yep+2;
                    yep+=2;
                    f++;
                }
            }
            // cout<<n<<" "<<f<<endl;
            n--;
        }

        fans=f;

        n=ncopy;
        n-=2;
        sans=1;
        f=sans;
        yep=4;
        fend=4;
        while(n>0) {

            if(f!=fend) {
                if(fend!=1)
                f++;
                else 
                f--;
            } else {
                f--;

                if(fend!=1)
                fend=1;
                else {   
                    fend=yep+2;
                    yep+=2;
                    f++;
                }
            }
            // cout<<n<<" "<<f<<endl;
            n--;
        }

        sans=f;

    }

    cout<<"TERM "<<inp<<" IS "<<fans<<"/"<<sans<<endl;

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
