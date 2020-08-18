#include<bits/stdc++.h>

using namespace std;

int main() {
    int n=5;
    int arr[]={5,3,4,7,9};
    int reqd=7;

    int p1=0;
    int p2=0;

    int sum=arr[0];
    int mn=INT_MAX-50;

    while(p2<n) {
        cout<<p1<<" "<<p2<<" "<<sum<<endl;

        while(p1<n && sum>reqd) {
            sum-=arr[p1++];
        }
        if(sum==0){
            if(p1!=n) {
                sum+=arr[++p2];
            }
        }
        while(p2<n && sum<reqd) {
            sum+=arr[++p2];
        }

        if(sum==reqd) {
            mn=min(mn,p2-p1+1);
            sum-=arr[p1++];
            if(mn==1)
                p2++;
            // if(mn==1)
            //     break;
        }
    }

    cout<<mn<<endl;

}
