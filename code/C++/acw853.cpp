#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

struct side
{
    int st; // 起点
    int ed; // 终点
    int w;  // 权重
};

vector<side> sides;

int dist[510];
int cpy[510];
int n, m, k;
int x, y, z;

int main()
{
    memset(dist, 0x3f, sizeof dist);

    cin >> n >> m >> k;
    while(m--)
    {
        cin >> x >> y >> z;
        sides.push_back({x, y, z});
    }
    dist[1] = 0;
    for(int i = 0; i < k; i++)
    {
        for(int j = 1; j <= n; j++)cpy[j] = dist[j];
        for(auto s : sides)
        {
            dist[s.ed] = min(dist[s.ed], cpy[s.st] + s.w);
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2)cout << "impossible";
    else cout << dist[n];
    return 0;
}