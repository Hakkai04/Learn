#include <bits/stdc++.h>
using namespace std;

// 深度为种群
const int N = 1e5 + 10;
int p[N], d[N];
int fakes;

int find(int x)
{
    if (x != p[x])
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (k--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        // 若XY比N大则为假
        if (x > n || y > n)
        {
            fakes++;
            continue;
        }
        // 若冲突则为假
        else
        {
            int px = find(x), py = find(y);
            if (a == 1)
            {
                if (px == py && (d[x] - d[y]) % 3)
                    fakes++;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3)
                    fakes++;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << fakes;
    return 0;
}