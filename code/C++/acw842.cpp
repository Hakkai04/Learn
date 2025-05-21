#include <bits/stdc++.h>
using namespace std;

bool v[10];
int d[10];
int n;

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            cout << d[i] << ' ';
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            d[x] = i;
            v[i] = true;
            dfs(x + 1);
            v[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}