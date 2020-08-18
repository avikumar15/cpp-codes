#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.length();
        int freqs1[26] = {0}, freqs2[26] = {0};
        int len = s2.length();
        for (int i = 0; i < len; i++)
        {
            freqs2[s2[i] - 'a']++;
        }
        int l = 0, r = 0;
        int cnt = 0;
        int minl = 0, minr = n - 1;
        bool flag = false;

        // s1 timetopractice
        // s2 toc

        for (r = 0; r < n; r++)
        {
            freqs1[s1[r] - 'a']++;
            if (freqs2[s1[r] - 'a'] >= freqs1[s1[r] - 'a'] && cnt < len)
            {
                cnt++;
            }
            cout<<r<<" "<<cnt<<" "<<len<<endl;
            if (cnt == len)
            {
                while (freqs2[s1[l] - 'a'] < freqs1[s1[l] - 'a'])
                {
                    freqs1[s1[l] - 'a']--;
                    l++;
                }
                flag = true;
                if (r - l + 1 < minr - minl + 1)
                {
                    minr = r;
                    minl = l;
                }
                freqs1[s1[l] - 'a']--;
                l++;
                cnt--;
            }
        }
        if (flag == false)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << s1.substr(minl, minr - minl + 1) << endl;
        }
    }
}
