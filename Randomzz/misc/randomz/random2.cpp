/*
    This code belongs to Harshit Agrawal(106118036)
    Code it until u crack it
*/
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define int long long
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define mod 1000000007
// #define endl "\n"
struct Task
{
    int client;
    int proc;
    int time;
};
int randrange(int lower, int upper)
{
    return (rand() % upper - lower + 1) + lower;
}
Task findclient(vector<Task> tasks, int t)
{
    int n = tasks.size();
    bool flag = false;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (tasks[i].time == t)
        {
            flag = true;
            index = i;
            break;
        }
    }
    if (flag == true)
        return tasks[index];
}
void clientsleep(vector<Task> &tasks, int t, int cnt)
{
    int n = tasks.size();
    for (int i = 0; i < n; i++)
    {
        if (tasks[i].time == t)
        {
            tasks[i].time += min(1LL, randrange(min(cnt - 5, 0LL), cnt + 5));
        }
    }
}
bool comp(Task a, Task b)
{
    return a.time < b.time;
}
int32_t main()
{
    srand(time(0)); // Using the current time as seed for randrange function
    fastio;
    cout << "Hello! I am the server " << endl;
    int m;
    cout << "Enter the number of procedures : " << flush;
    cin >> m;
    int proceduretime[m];
    // Enter the burst time of each procedure below
    for (int i = 0; i < m; i++)
    {
        cout << "Time taken to complete procedure " << i << " is : " << flush;
        cin >> proceduretime[i];
    }
    cout << endl;
    cout << "Enter the size of server side buffer queue" << endl;
    int qsize;
    cin >> qsize;
    queue<Task> buffer; // Creating a buffer double ended queue
    int n;
    cout << endl;
    cout << "Enter the number of Clients : " << flush;
    cin >> n;
    cout << endl;
    // Taking input for number of requests
    cout << "Enter the number of times the clients send requests to the server : " << flush;
    int req;
    cin >> req;
    vector<Task> tasks(req);
    cout << endl;
    cout << "Enter task details :" << endl;
    for (int i = 0; i < req; i++)
    {
        cout << "<---------" << i << "--------->" << endl;
        cout << "Client - " << flush;
        cin >> tasks[i].client;
        cout << "Procedure - " << flush;
        cin >> tasks[i].proc;
        cout << "Time - " << flush;
        cin >> tasks[i].time;
    }
    cout << "<---------END--------->" << endl;
    int t = 0;
    int cnt = 0;
    int tcurr = 0;
    sort(tasks.begin(), tasks.end());
    while (1)
    {

        if (tcurr == 0)
        {
            Task currclient;
            if (!buffer.empty())
            {
                currclient = buffer.front();
            }
            Task newclient = findclient(tasks, t);
            cout << "Client - " << flush;
            cout << currclient.client << endl;
            cout << "Procedure - " << flush;
            cout << currclient.proc << endl;
            cout << "Time - " << flush;
            cout << currclient.time << endl;
            tcurr = currclient.time;
            cnt += tcurr;
        }
    }
}
