int Solution::books(vector<int> &A, int B) {
    vector<int> vec=A;
    long long n=A.size();
    long long h=0;
    long long l=0;
    
    if(B>A.size())
        return -1;
        
    for(long long i=0; i<n; i++) {
        h+=A[i];
        l=max(l,(long long) A[i]);
    }
    
    if(B==A.size())
        return l;
    
    long long m=l+(h-l)/2;
    
    while(h>=l) {
        m=l+(h-l)/2;
        
        long long k=1;
        long long sum=0;
        // 12 34 67 90
        
        for(long long i=0; i<n; i++) {
            if(sum+vec[i]<=m) {
                sum+=vec[i];
            } else {
                sum=vec[i];
                k++;
            }
        }
        
        if(k>B) {
            l=m+1;
        } else {
            h=m-1;
        }
        
    }
    
    return l;
}
