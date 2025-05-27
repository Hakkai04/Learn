#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
typedef pair<int, int> ii;
map<int, vector<ii>> mp;
queue<int> q;
bool exist[N];
int dist[N];
int n, m;
int x, y, z;

int main()
{
    memset(dist, 0x3f, sizeof dist);

    cin >> n >> m;
    while(m--)
    {
        cin >> x >> y >> z;
        mp[x].push_back({y, z});
    }

    q.push(1);
    dist[1] = 0;
    exist[1] = true;

    while(!q.empty())
    {
        int site = q.front();
        q.pop();
        exist[1] = false;

        for(auto i : mp[site])
        {
            if(dist[i.first] > dist[site] + i.second)
            {
                dist[i.first] = dist[site] + i.second;
                q.push(i.first);
                exist[i.first] = true;
            }
        }
    }
    if(dist[n] >= 0x3f3f3f3f / 2)cout << "impossible";
    else cout << dist[n];
    return 0;
}