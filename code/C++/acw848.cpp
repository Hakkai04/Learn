#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
map<int, vector<int>> mp;
priority_queue<int, vector<int>, greater<int>> q;
int in[N];
bool exists[N];
int n, m;
int x, y;
vector<int> res;


int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        mp[x].push_back(y);
        in[y]++;
    }
    for(int i = 1; i <= n; i++)exists[i] = true;
    
    for(int i = 1; i <= n; i++)if(in[i] == 0 && exists[i] == true)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        int site = q.top();
        q.pop();
        res.push_back(site);
        exists[site] = false;
        for(auto c : mp[site])
        {
            if(exists[c])
            {
                in[c]--;
                if(in[c] == 0)q.push(c);
            }
        }
    }
    
    bool alls = true;
    for(int i = 1; i <= n; i++)
    {
        if(exists[i])alls = false;
    }
    if(alls)for(auto i : res)cout << i << ' ';
    else cout << -1;
    return 0;
}