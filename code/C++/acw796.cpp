#include <bits/stdc++.h>
using namespace std;

int a[1010][1010];
int S[1010][1010];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            S[i][j] = S[i][j - 1] + a[i][j];
        }
    }

    int x1, y1, x2, y2;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for (int i = x1; i <= x2; i++)
        {
            sum += S[i][y2] - S[i][y1 - 1];
        }
        cout << sum << endl;
    }
    return 0;
}