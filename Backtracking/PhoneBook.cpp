#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    void solve(map<char,string> mmap, string digits, vector<string>& vec, int l) {
        
        if(l==digits.size()) {
            vec.push_back(digits);
            return;
        }
        
        for(int i=0; i<mmap[digits[l]].size(); i++) {
            char dl=digits[l];
            digits[l]=mmap[digits[l]][i];
            solve(mmap,digits,vec,l+1);
            digits[l]=dl;
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        map<char,string> mmap;
        
        mmap['2']="abc";
        mmap['3']="def";
        mmap['4']="ghi";
        mmap['5']="jkl";
        mmap['6']="mno";
        mmap['7']="pqrs";
        mmap['8']="tuv";
        mmap['9']="wxyz";
        
        vector<string> vec;
        
        if(digits.size()==0)
            return vec;
        
        int n=digits.size();
        
        solve(mmap,digits,vec,0);
        
        return vec;
    }
};
