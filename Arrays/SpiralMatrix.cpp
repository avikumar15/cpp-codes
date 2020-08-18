#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int n,m;
        cin>>n>>m;
        
        int G[n+5][m+5];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                cin>>G[i][j];
        }
        
        int cnt=1;
        
        int i=0;
        int j=0;
        
        while(1) {
            if(G[i][j]==-1)
                break;
            if(cnt%4==1) {
                while(j<m && G[i][j]!=-1) {
                    cout<<G[i][j]<<" ";
                    G[i][j++]=-1;
                }
                j--;
                i++;
            } else if(cnt%4==2) {
                while(i<n && G[i][j]!=-1) {
                    cout<<G[i][j]<<" ";
                    G[i++][j]=-1;
                }
                i--;
                j--;
            } else if(cnt%4==3) {
                while(j>=0 && G[i][j]!=-1) {
                    cout<<G[i][j]<<" ";
                    G[i][j--]=-1;
                }
                i--;
                j++;
            } else {
                while(i>=0 && G[i][j]!=-1) {
                    cout<<G[i][j]<<" ";
                    G[i--][j]=-1;
                }
                i++;
                j++;
            }
            cnt++;
        }
        cout<<"\n";
    }
	return 0;
}
