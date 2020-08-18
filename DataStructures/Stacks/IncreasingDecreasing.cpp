#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string s="IIDDIDID";
	int n=s.size();
	stack<int> st;
 
	int var=2;
	st.push(1);
	vector<int> res;
 
	for(int i=1; i<=n; i++) {
		if(s[i-1]=='I') {
			while(!st.empty()) {
				int t=st.top();
				st.pop();
				res.push_back(t);
			}
			st.push(var++);
		} else {
			st.push(var++);
		}
	}

	while(!st.empty()) {
		int t=st.top();
		st.pop();
		res.push_back(t);
	}
 
	for(int i=0; i<n; i++) {
		cout<<res[i]<<" ";
	}
	cout<<endl;
 
	return 0;
}
