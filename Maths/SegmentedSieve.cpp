#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>

using namespace std;

vi primes;

void sieve(int n) {

    vector<bool> mark(n+5,true);
    
    // run from 2 till sqrt(n), and mark all of their multiple as false, if it itself is true.
    for(int i=2; i*i<n; i++) {
        if(mark[i]) {
            int s=i*i;
            for(int j=s; j<n; j+=i) {
                mark[j]=false;
            }
        } else {
            continue;
        }
    }

    // whichever mark is true are primes.
    for(int i=2; i<n; i++) {
        if(mark[i])
        primes.push_back(i);
    }

}  

void segmentedSieve(int n) {
    
    // storing prime numbers till 1 to sqrt(n).
    int lim = sqrt(n)+1;
    sieve(lim);

    int ps = primes.size();

    // creating first segment.
    int low=lim;
    int high=2*lim;

    // traversing through all segments.
    while(low<n) {

        // if high>n making it n.
        if(high>n) {
            high=n;
        }
        
        // marks primes in low to high range.
        vector<bool> arr(high-low+5,true);

        // traversing through each element of primes.
        for(int i=0; i<ps; i++) {            
            
            // finding first number divisible by primes just more than low.
            int first=(low/primes[i])*primes[i];
            if(first<low) {
                first+=primes[i];
            }
        
            // marking all its multiples as false.
            for(int s=first; s<high; s+=primes[i]) {
                arr[s-low]=false;
            }

        }

        // wherever marker is true, pushing that number inside the vector.
        for(int i=low; i<high; i++) {
            if(arr[i-low]) {
                primes.push_back(i);
            }
        }

        // moving to next segment.
        low+=lim;
        high+=lim;

    }


}

int32_t main() {
    
    int n;
    cin>>n;

    segmentedSieve(n+1);

    for(int i=0; i<primes.size(); i++) {
        cout<<primes[i]<<" ";
    }

    cout<<endl;

}
