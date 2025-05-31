#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 210;
const int INF = 0x3f3f3f3f;

int dist[N][N];
int n, m, k;
int x, y, z;

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    while (m--)
    {
        cin >> x >> y >> z;
        dist[x][y] = min(dist[x][y], z);
    }

    for (int t = 1; t <= n; t++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);
    
    while(k--)
    {
        cin >> x >> y;
        if(dist[x][y] > INF / 2)cout << "impossible" << endl;
        else cout << dist[x][y] << endl;
    }
    return 0;
}