#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
typedef pair<int, int> ii;
unordered_map<int, vector<ii>> mp;
deque<int> q;
bool exists[N];
int dist[N];
int cnt[N];
int x, y, z;
int n, m;

int main()
{
    cin >> n >> m;
    while(m--)
    {
        scanf("%d%d%d", &x, &y, &z);
        mp[x].push_back({y, z});
    }

    for(int i = 1; i <= n; i++)
    {
        q.push_back(i);
        exists[i] = true;
    }

    while(!q.empty())
    {
        int site = q.front();
        q.pop_front();
        exists[site] = false;
        for(auto i : mp[site])
        {
            if(dist[i.first] > dist[site] + i.second)
            {
                dist[i.first] = dist[site] + i.second;
                cnt[i.first] = cnt[site] + 1;
                if(cnt[i.first] >= n)
                {
                    cout << "Yes";
                    return 0;
                }
                if(!exists[i.first])
                {
                    q.push_front(i.first);
                    exists[i.first] = true;
                }
            }
        }
    }
    cout << "No";
    return 0;
}