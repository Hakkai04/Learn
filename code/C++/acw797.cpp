#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int S[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        S[i] = a[i] - a[i - 1];
    }

    int l, r, c;
    while(m--)
    {
        scanf("%d%d%d", &l, &r, &c);
        S[l] += c;
        S[r+1] -= c;
    }

    int x = 0;
    for(int i = 1; i <= n; i++)
    {
        x += S[i];
        cout << x << ' ';
    }
    return 0;
}