#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int u, v;
map<int, vector<int>> mp;
queue<int> q;
int p[N];

int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
            p[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            int site = q.front();
            q.pop();
            for (auto i : mp[site])
            {
                if (p[i] == 0)
                {
                    p[i] = 0 - p[site];
                    q.push(i);
                }
                else if (p[i] == 0 - p[site])
                    continue;
                else if (p[i] == p[site])
                {
                    cout << "No";
                    return 0;
                }
            }
        }
    }

    bool sp = true;
    for (int i = 1; i <= n; i++)
        if (p[i] == 0)
            sp = false;
    if (sp)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}