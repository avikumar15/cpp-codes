#include<bits/stdc++.h>

using namespace std;

int reverseNum(int n) {
    
    int ans=0;

    while(n>0) {
        
        ans*=10;
        ans+=n%10;
        n/=10;

    }

    return ans;
}

bool isPalindrome(int n) {
    if(n==reverseNum(n))
        return true;
    return false;    
}

int main() {
    int n=37559;
    
    n+=reverseNum(n);
    int cnt=1;
    
    while(!isPalindrome(n)) {
        n+=reverseNum(n);
        cnt++;
    }

    cout<<cnt<<endl;
}
