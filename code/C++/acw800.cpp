#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0, j = m - 1; i < n, j >= 0;)
    {
        int t = a[i] + b[j];
        if (t == x)
        {
            cout << i << ' ' << j;
            return 0;
        }
        else if (t > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}