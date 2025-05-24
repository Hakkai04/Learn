#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
map<int, vector<int>> mp;
int res;
int n, a, b;
bool father[N];
int childs[N];
int minx = 0x3f3f3f3f;
int maxxx = 0x3f3f3f3f;

int dfs(int x)
{
    if(childs[x] != -1)return childs[x];
    int numm = 0;
    for(auto i : mp[x])
    {
        numm += dfs(i);
    }
    childs[x] = numm + 1;
    return childs[x];
}

int main()
{
    memset(childs, -1, sizeof childs);
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        if(!father[a] && father[b])swap(a, b);
        mp[a].push_back(b);
        father[b] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        if(mp[i].empty())continue;
        int sum = 0;
        int maxx = 0;
        for(auto c : mp[i])
        {
            int num = dfs(c);
            maxx = max(maxx, num);
            sum += num;
        }
        maxx = max(maxx, n - 1 - sum);
        // cout << i << ' ' << maxx << endl;
        // 取小者
        if(maxx <= minx)
        {
            if(maxx < maxxx)maxxx = maxx;
        }
    }
    cout << maxxx;
    return 0;
}