#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 110;
int maze[N][N];
int v[N][N];
int d[N][N];
ii cge[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;
queue<ii> q;

int main()
{
    memset(maze, 1, sizeof maze);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> maze[i][j];
    q.push({1, 1});
    d[1][1] = 0;
    v[1][1] = 1;
    while (!q.empty())
    {
        ii site = q.front();
        q.pop();
        if (site.first == n && site.second == m)
        {
            cout << d[site.first][site.second];
            return 0;
        }

        for (auto c : cge)
        {
            int x = site.first + c.first;
            int y = site.second + c.second;

            if (maze[x][y] == 0 && v[x][y] == 0)
            {
                d[x][y] = d[site.first][site.second] + 1;
                v[x][y] = 1;
                q.push({x, y});
            }
        }
    }
}