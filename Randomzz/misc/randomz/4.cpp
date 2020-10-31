#include <bits/stdc++.h>
#define vi vector<int>
#define int long long

using namespace std;

void fill(vector< vector<vector<int>> > &prestore, vector<bool> isGone, vector<vector<int>> temp,int row, int col) {

    if(row>2 || col>2)
        return;

    int nr=row,nc;
    nc=(col+1)%3;
    if(col==2)
        nr++;

    for(int i=1; i<=9; i++) {
        if(!isGone[i-1]) {
            isGone[i-1]=true;
            temp[row][col]=i;
            fill(prestore,isGone,temp,nr,nc);
            isGone[i-1]=false;
        }
    }

    // if(row==2 && col==2) {
    //     for(int i=0; i<3; i++) {
    //         for(int j=0; j<3; j++) {
    //             cout<<temp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<"*******"<<endl;
    // }

    if(row==2 && col==2) {
        vi sums;
        int s=0;
        for(int i=0; i<3; i++) {
            s+=temp[i][0];
        }
        sums.push_back(s);
        s=0;
        for(int i=0; i<3; i++) {
            s+=temp[i][1];
        }
        sums.push_back(s);
        s=0;
        for(int i=0; i<3; i++) {
            s+=temp[i][2];
        }
        sums.push_back(s);
        s=0;
        for(int i=0; i<3; i++) {
            s+=temp[0][i];
        }
        sums.push_back(s);
        s=0;
        for(int i=0; i<3; i++) {
            s+=temp[1][i];
        }
        sums.push_back(s);
        s=0;
        for(int i=0; i<3; i++) {
            s+=temp[2][i];
        }
        sums.push_back(s);
        sums.push_back(temp[0][0]+temp[1][1]+temp[2][2]);
        sums.push_back(temp[0][2]+temp[1][1]+temp[2][0]);

        int fu=1;
        for(int i=0; i<sums.size(); i++) {
            if(sums[i]!=sums[0]) {
                fu=-1;
                break;
            }
        }
        if(fu==1) {
            prestore.push_back(temp);
        }
    }
}

int32_t main() {
    
    int G[105][105];

    for(int i=0;i<3;i++) {
        for(int j=0; j<3; j++) {
            cin>>G[i][j];
        }
    }

    vector< vector<vector<int>> > prestore;
    vector<bool> isGone(9,false);
    vector<vector<int>> temp(3,vector<int>(3,0));

    fill(prestore,isGone, temp, 0, 0);
    int mn=LONG_LONG_MAX;

    for(int i=0; i<prestore.size(); i++) {
        int ans=0;
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                // cout<<prestore[i][j][k]<<" ";
                ans+=abs(prestore[i][j][k]-G[j][k]);
            }
            // cout<<endl;
        }
        mn=min(mn,ans);
        // cout<<endl<<"**********"<<endl;
    }
    cout<<mn<<endl;

}
