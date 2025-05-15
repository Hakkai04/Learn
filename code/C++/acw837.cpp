#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int p[N], num[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b)
{
    if (find(a) != find(b))
    {
        num[find(a)] += num[find(b)];
        p[find(b)] = find(a);
    }
}

void query(int a, int b)
{
    if (find(a) == find(b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void query2(int a)
{
    cout << num[find(a)] << endl;
}

void print()
{
    for(int i = 1; p[i]; i++)
    {
        cout << p[i] << ' ';
    }
    cout << endl;
    for(int i = 1; p[i]; i++)
    {
        cout << num[i] << ' ';
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        num[i] = 1;
    }

    string c;
    int a, b;
    while (m--)
    {
        cin >> c;
        if (c == "C")
        {
            cin >> a >> b;
            merge(a, b);
            // print();
        }
        else if (c == "Q1")
        {
            cin >> a >> b;
            query(a, b);
        }
        else if (c == "Q2")
        {
            cin >> a;
            query2(a);
        }
    }
    
    return 0;
}