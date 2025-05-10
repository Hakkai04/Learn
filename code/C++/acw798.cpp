#include <bits/stdc++.h>
using namespace std;

int a[1010][1010];
int S[1010][1010];

int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            S[i][j] = a[i][j] - a[i][j-1];
        }
    }

    int x1, y1, x2,y2, c;
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        for(int i = x1; i <= x2; i++)
        {
            S[i][y1] += c;
            S[i][y2+1] -= c;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        int x = 0;
        for(int j = 1; j <= m; j++)
        {
            x += S[i][j];
            cout << x << ' ';
        }
        cout << endl;
    }
    return  0;
}