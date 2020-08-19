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

string strAdd(string a, string b) {

    int an=a.size()-1;
    int bn=b.size()-1;
    string res="";
    int carry=0;
    int current=0;

    while(an>=0 && bn>=0) {

        int num=a[an]+b[bn]-'0'-'0'+carry;
        
        carry=(num)/10;
        current=(num)%10;
        res+=to_string(current);

        an--;
        bn--;
    }

    if(an>=0) {
        while(an>=0) {
            
            int num=a[an]-'0'+carry;

            carry=(num)/10;
            current=(num)%10;
            res+=to_string(current);

            an--;
        }
    } else {
        while(bn>=0) {

            int num=b[bn]-'0'+carry;

            carry=(num)/10;
            current=(num)%10;
            res+=to_string(current);

            bn--;
        }
    }

    if(carry!=0) {
        res+=to_string(carry);
    }

    reverse(res.begin(),res.end());
    return res;
}

string strHalf(string a) {

    int an=a.size()-1;
    string res="";
    int rem=0;

    for(int i=0; i<a.size(); i++) {
        int num=rem*10+a[i]-'0';
        res+=to_string(num/2);
        rem=num%2;
    } 

    // reverse(res.begin(),res.end());
    return res;
}

string strSub(string a, string b) {

    int an=a.size()-1;
    int bn=b.size()-1;

    string res="";
    int borrow=0;
    int current=0;

    while(an>=0 && bn>=0) {

        int num;

        if((a[an]-borrow)>=b[bn]){
            num=a[an]-borrow-b[bn];
            borrow=0;
        }
        else {
            num=10+a[an]-b[bn]-borrow;
            borrow=1;
        }

        res+=to_string(num);

        an--;
        bn--;
    }

        while(an>=0) {
            
            int num;
            
            if((a[an]-borrow)>='0'){
                num=a[an]-borrow-'0';
                borrow=0;
            }
            else {
                num=10+a[an]-'0'-borrow;
                borrow=1;
            }

            res+=to_string(num);

            an--;
        }

    reverse(res.begin(),res.end());
    return res;
}
 
string removeZero(string s) {
    
    int i=0;
    while(s[i]=='0') {
        i++;
    }
    return s.substr(i);
}

int32_t main() {
    fastio;
 
    int t=10;
//    cin>>t;
 
    while(t--) {

        string n,k;
        cin>>n>>k;

     //   cout<<strAdd(n,k)<<endl;
     //   cout<<strSub(n,k)<<endl;
    //    cout<<strSub(n,k)<<endl;
     //   cout<<strHalf(strSub(n,k))<<endl;
    
        string a=removeZero(strHalf(strSub(n,k)));
        cout<<removeZero(strSub(n,a))<<endl;
        cout<<a<<endl;

    }
    return 0;
}
