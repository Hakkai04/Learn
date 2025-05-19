#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int q[N];
int idx;

void down(int x)
{
    int t = x;
    if (2 * x <= idx && q[t] > q[2 * x])
        t = 2 * x;
    if (2 * x + 1 <= idx && q[t] > q[2 * x + 1])
        t = 2 * x + 1;
    if (t != x)
    {
        swap(q[x], q[t]);
        down(t);
    }
}

void print()
{
    for (int i = 1; i <= idx; i++)
        cout << q[i] << ' ';
    cout << endl;
}

int main()
{
    int n, m, x;
    cin >> n >> m;
    while (n--)
    {
        cin >> x;
        q[++idx] = x;
    }
    for (int i = idx / 2; i; i--)
    {
        down(i);
        //print();
    }

    while (m--)
    {
        cout << q[1] << ' ';
        q[1] = q[idx--];
        down(1);
    }
    return 0;
}