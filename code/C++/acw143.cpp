#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, M = 31 * N;

int son[M][2], idx;
int res;

void insert(int x)
{
    int p = 0;
    for(int i = 30; i >=0; i--)
    {
        int &s = son[p][x >> i & 1];
        if(!s)s = ++idx;
        p = s;
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i--)
    {
        int s = x >> i & 1;
        if(son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        insert(a);
        res = max(res, query(a));
    }
    cout << res;
    return 0;
}
