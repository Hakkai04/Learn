#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int side[N][N];     // 边
int dist[N];        // 距离
int is_shortest[N]; // 是否为最短路
int n, m;
int x, y, z;

int main()
{
    memset(side, 0x3f, sizeof side);
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y >> z;
        side[x][y] = min(side[x][y], z);
    }

    dist[1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        // 找到路径最短点
        for (int j = 1; j <= n; j++)
        {
            if (!is_shortest[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        // 更新其他点距离
        for (int k = 1; k <= n; k++)
        {
            dist[k] = min(dist[k], dist[t] + side[t][k]);
        }
        // cout << t << ' ' << dist[t] << endl;
        is_shortest[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f)
        cout << -1;
    else
        cout << dist[n];

    return 0;
}