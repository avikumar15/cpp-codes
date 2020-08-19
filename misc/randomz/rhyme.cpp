#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
#define cout cout<<setprecision(15)
 
using namespace std;


void solve() {
    int n,k,kcopy;
    cin>>n>>k;
    kcopy=k;

    vector<string> strs;
    vector<string> rhymes;
    string str;
    int fu=1;

    for(int i=0; i<4*n; i++) {
        cin>>str;
        strs.push_back(str);
    }

    for(int i=0; i<4*n; i+=4) {
        int n1=strs[i].size(),n2=strs[i+1].size(),n3=strs[i+2].size(),n4=strs[i+3].size();
        int start=n1-1;

        while(k!=0 && start>=0) {
            if(strs[i][start]=='a' || strs[i][start]=='e' || strs[i][start]=='i' || strs[i][start]=='o' || strs[i][start]=='u') {
                k--;
            }
            start--;
        }

        if(k!=0) {
            fu=-1;
        }

        string s1,s2,s3,s4;
        s1=strs[i].substr(start+1);

        start=n2-1;
        k=kcopy;

        while(k!=0 && start>=0) {
            if(strs[i+1][start]=='a' || strs[i+1][start]=='e' || strs[i+1][start]=='i' || strs[i+1][start]=='o' || strs[i+1][start]=='u') {
                k--;
            }
            start--;
        }
        s2=strs[i+1].substr(start+1);

        if(k!=0) {
            fu=-1;
        }

        start=n3-1;
        k=kcopy;

        while(k!=0 && start>=0) {
            if(strs[i+2][start]=='a' || strs[i+2][start]=='e' || strs[i+2][start]=='i' || strs[i+2][start]=='o' || strs[i+2][start]=='u') {
                k--;
            }
            start--;
        }
        s3=strs[i+2].substr(start+1);

        if(k!=0) {
            fu=-1;
        }

        start=n4-1;
        k=kcopy;

        while(k!=0 && start>=0) {
            if(strs[i+3][start]=='a' || strs[i+3][start]=='e' || strs[i+3][start]=='i' || strs[i+3][start]=='o' || strs[i+3][start]=='u') {
                k--;
            }
            start--;
        }

        if(k!=0) {
            fu=-1;
        }

        s4=strs[i+3].substr(start+1);

        k=kcopy;

        string result="";


        // cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;

        if(s1==s2) {
            if(s2==s3) {
                if(s3==s4) {
                    result="aaaa";
                } else {
                    result="none";
                }
            } else {
                if(s3==s4) {
                    result="aabb";
                } else {
                    result="none";
                }
            }
        } else {
            if(s1==s3) {
                if(s2==s4) {
                    result="abab";
                } else {
                    result="none";
                }
            } else {
                if(s1==s4) {
                    if(s2==s3) {
                        result="abba";
                    } else {
                        result="none";
                    }
                } else {
                    result="none";
                }
            }
        
        }

        rhymes.push_back(result);

    }

    
    string finalfinal;
    string last = rhymes[0];

    if(last=="none" || fu==-1) {
        finalfinal="NO\n";
    }
    else {
        for(int i=1; i<rhymes.size(); i++) {
            if(rhymes[i]=="none") {
                fu=-1;
                break;
            }
            if(rhymes[i]==last || rhymes[i]=="aaaa") {
                continue;
            } else {
                if(last=="aaaa") {
                    last=rhymes[i];
                    continue;
                } else {
                    fu=-1;
                    break;
                }
            }
        }
        if(fu==-1) {
            finalfinal="NO\n";
        } else {
            finalfinal=last;
            finalfinal+="\n";
        }
    }

    cout<<finalfinal;

}
 
int32_t main() {
//    fastio;
 
    int t=1;
//    cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}