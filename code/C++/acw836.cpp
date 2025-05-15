#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b)
{
    p[find(b)] = find(a);
}

void query(int a, int b)
{
    if (find(a) == find(b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'M')
            merge(a, b);
        else if (c == 'Q')
            query(a, b);
    }
    return 0;
}