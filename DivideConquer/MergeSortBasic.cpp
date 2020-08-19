#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

void mergeVI(vi &a, int l, int m, int h) {
    vi b;
    vi c;
    
    for(int i=l; i<=m; i++) {
        b.push_back(a[i]);
    }
    
    for(int i=m+1; i<=h; i++) {
        c.push_back(a[i]);
    }

    int currentb=0;
    int currentc=0;

    while(currentb<b.size() && currentc<c.size()) {
        if(b[currentb]<c[currentc]) {
            a[l]=b[currentb];
            l++;
            currentb++;
        } else {
            a[l]=c[currentc];
            l++;
            currentc++;
        }
    }

    if(currentc<c.size()) {
        for(int i=currentc; i<c.size(); i++) {
            a[l]=c[i];
            l++;
        }
    }
    if(currentb<b.size()) {
        for(int i=currentb; i<b.size(); i++) {
            a[l]=b[i];
            l++;
        }
    }
    
    cout<<"SEMI-SORTED-----\n";
    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void msort(vi &a, int l, int h) {
    if(l>=h) return;

    int m=(l+h)/2;
    msort(a,l,m);
    msort(a,m+1,h);
    
    mergeVI(a,l,m,h);

}

int main() {
    vi vec;
    
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);

    cout<<"ORIGINAL\n";
    for(int i=0; i<vec.size(); i++) {
        cout<<vec[i]<<" ";
    }

    cout<<endl;

    msort(vec, 0, vec.size()-1);

    cout<<"SORTED : "<<endl;
    for(int i=0; i<vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    
    return 0; 
}