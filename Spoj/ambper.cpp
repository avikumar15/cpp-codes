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

int32_t main() {
    
    fastio;

    int t=1;
//    cin>>t;
 
    while(1) {
        int n;

        cin>>n;

        vi vec((n+5),-1);
        vi vec2((n+5),-1);

        int temp;
        int fu=1;

        FORN(1,n) {
            cin>>temp;

            vec[i]=temp;
            vec2[temp]=i;

            // cout<<i<<" "<<temp<<" "<<vec2[i]<<" "<<vec[temp]<<endl;
            if(i>temp) {
                if(vec2[i]==temp) {
                    // ok
                } else {
                    fu=-1;
                }
            }
        }

        if(n==0) {
            break;
        }

        if(fu==-1) {
            cout<<"not ambiguous"<<endl;
        } else {
            cout<<"ambiguous"<<endl;
        }


    }

    return 0;
}
