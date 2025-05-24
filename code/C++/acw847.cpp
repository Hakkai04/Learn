#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int a, b;
map<int, vector<int>> mp;
queue<int> q;
int v[N];
int res;

void bfs()
{
    q.push(1);
    v[1] = 0;
    while (!q.empty())
    {
        int site = q.front();
        q.pop();
        for (auto c : mp[site])
        {
            if (c == n)
            {
                cout << v[site] + 1;
                return;
            }
            if (v[c] == -1)
            {
                q.push(c);
                v[c] = v[site] + 1;
            }
        }
    }
    cout << -1;
}
int main()
{
    memset(v, -1, sizeof v);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        mp[a].push_back(b);
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    bfs();
    return 0;
}