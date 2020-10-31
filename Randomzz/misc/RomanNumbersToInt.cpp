#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        
        map<char,pair<int,int>> mmap;
        mmap['I']={1,1};
        mmap['V']={5,1};
        mmap['X']={10,1};
        mmap['L']={50,10};
        mmap['C']={100,10};
        mmap['D']={500,100};
        mmap['M']={1000,100};
        int ans=0;
        
        for(int i=0; i<n; i++) {
            int j = i;
            
            while(j+1<n && mmap[s[j+1]].first>mmap[s[j]].first) 
                j++;
            
            int cnt=j-i;
            ans+=mmap[s[j]].first-cnt*mmap[s[j]].second;    
            i=j;
        }
        
        return ans;
    }
};
