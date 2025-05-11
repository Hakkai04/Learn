#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0, j = 0; j < m;)
    {

        if (a[i] == b[j])
        {
            i++;
            j++;
            if (i == n)
            {
                cout << "Yes";
                return 0;
            }
        }
        else
            j++;
    }
    cout << "No";
    return 0;
}