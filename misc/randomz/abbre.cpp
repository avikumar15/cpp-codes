#include <bits/stdc++.h>

using namespace std;

void solve(string a, string b, int s, int &fu, vector<vector<int>> &vec, int inita) {
    
    if(fu==1) {
        return;
    }

    if(vec[s][inita-a.size()]==0) {
        return;
    }

    int cunt=1;

    for(int i=0; i<a.size(); i++) {

        if(s==b.size() && a[i]>='A' && a[i]<='Z') {
            cunt=-1;
            break;
        } 
        if(s<b.size() && a[i]==b[s]) {
            s++;
            continue;
        }

        if(s<b.size() && a[i]>='A' && a[i]<='Z' && a[i]!=b[s]) {
            // mark false kinda
            cunt=-1;
            break;
        }
        if(s<b.size() && (a[i]+('A'-'a'))==b[s]) {
            solve(a.substr(i+1),b,s,fu,vec,inita);
            solve(a.substr(i+1),b,s+1,fu,vec,inita);
            break;
        }
    }

    if(cunt==1 && s==b.size()) {
        fu=1;
    } else {
        for(int i=s; i>=0; i--) {
            if(vec[i][inita-a.size()]==0) {
                break;
            }
            for(int j=inita-a.size(); j<inita; j++) {
                vec[i][j]=0;
            }
        }
        cout<<"\n-----DEBUG------\n";
        for(int i=0; i<b.size(); i++) {
            for(int j=0; j<inita; j++) {
                cout<<vec[i][j]<<" ";
            }
            cout<<endl;
        }

    }

}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {

    int fu=-1;
    vector<vector<int>> mmap;
    for(int i=0; i<a.size()+13; i++) {
        vector<int> temp;
        for(int j=0; j<b.size()+13;j++)
            temp.push_back(-1);
        mmap.push_back(temp);
    }

    solve(a,b,0,fu,mmap,a.size());

    if(fu==1) {
        return "YES";
    } else {
        return "NO";
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
