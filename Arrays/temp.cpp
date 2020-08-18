#include <bits/stdc++.h>
using namespace std;
void check(int n, int **a)
{
    int i = 1, j = 1;
    cout << a[i] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        check(n, (int **)a);
    }
}