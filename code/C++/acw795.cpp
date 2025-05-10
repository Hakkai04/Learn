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
        if (i == 1)
            S[i] = a[i];
        else
            S[i] = S[i - 1] + a[i];
    }

    int l, r;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        cout << S[r] - S[l - 1] << endl;
    }
    return 0;
}