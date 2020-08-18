#include<bits/stdc++.h>

using namespace std;

int main() {
    
    int *a = new int[100];

    for(int i=1; i<=90; i++)
        *(a+i-1)=2*i;

    for(int i=0; a[i]!='\0' ; i++) {
        cout<<a[i]<<" ";
    }

    // char* ch = new char[100];

    // for(int i=0; i<100; i++)
    //     *(ch+i)=i%26+'a';

    // for(int i=0; i<strlen(ch); i++)
    //     cout<<ch[i];

    



}
