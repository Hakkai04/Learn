#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
typedef pair<int, int> ii;
unordered_map<int, unordered_map<int, int>>mp;
priority_queue<ii, vector<ii>, greater<ii>> q;
int dist[N];
bool shortest[N];
int n, m;
int x, y, z;

int dijkstra()
{
    q.push({0, 1});
    dist[1] = 0;

    while(!q.empty())
    {
        ii site = q.top();
        q.pop();

        if(shortest[site.second])continue;
        shortest[site.second] = true;

        for(auto c : mp[site.second])
        {
            if(dist[c.first] > dist[site.second] + c.second)
            {
                dist[c.first] = dist[site.second] + c.second;
                q.push({dist[c.first], c.first});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f)return -1;
    else return dist[n];
}

int main()
{
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y >> z;
        if(mp[x][y] == 0)mp[x][y] = 0x3f3f3f3f;
        if(mp[x][y] > z)mp[x][y] = z;
    }

    cout << dijkstra() << endl;
    return 0;
}