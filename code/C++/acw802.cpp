#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int N = 1e6 + 10;

vector<ii> query;
vector<ii> vec;
vector<int> alls;
int a[N];
int S[N]; // 前缀和

int find(int x)
{
    int l = 0;
    int r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}
int main()
{
    int n, m, x, c, l, r;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> c;
        vec.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto v : vec)
    {
        int pos = find(v.first);
        a[pos] += v.second;
    }

    for (int i = 1; i <= alls.size(); i++)
        S[i] = S[i - 1] + a[i];

    for (auto i : query)
    {
        int l = find(i.first), r = find(i.second);
        cout << S[r] - S[l - 1] << endl;
    }

    return 0;
}