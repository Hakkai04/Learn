#include <bits/stdc++.h>
using namespace std;

const int M = 2e6 + 10;
const int N = 1e6;
struct Side
{
    int a;
    int b;
    int w;
    bool operator<(const Side &s) const
    {
        return w < s.w;
    }
};

vector<Side> sides;
int p[N];
int n, m;
int u, v, w;
int res;
int cnt;

int find(int x)
{
    if (p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        sides.push_back({u, v, w});
    }
    sort(sides.begin(), sides.end());
    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (auto s : sides)
    {
        int a = s.a, b = s.b, w = s.w;
        //cout << a << ' ' << b << endl;
        //cout << find(a) << ' ' << find(b) << endl;
        int x = find(a);
        int y = find(b);
        if (x != y)
        {
            p[y] = x;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1)
        cout << "impossible";
    else
        cout << res;
    return 0;
}