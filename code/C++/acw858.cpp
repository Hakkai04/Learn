#include<bits/stdc++.h>
using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;
int side[N][N];
int dist[N];
int exists[N];
int n, m;
int u, v, w;
int res;

int main()
{
    cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    memset(side, 0x3f, sizeof side);

    while(m--)
    {
        cin >> u >> v >> w;
        side[u][v] = min(side[u][v], w);
        side[v][u] = side[u][v];
    }

    exists[0] = true;
    res = 0;

    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(exists[j])continue;
            if(t == -1 || dist[t] > dist[j])t = j;
        }
        if(i && dist[t] == INF)
        {
            cout << "impossible";
            return 0; 
        }
        if(i)res += dist[t];
        exists[t] = true;

        for(int k = 1; k <= n; k++)dist[k] = min(dist[k], side[t][k]);
    }
    cout << res;
    return 0;
}