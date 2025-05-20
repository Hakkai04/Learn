#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, null = 0x3f3f3f3f;
int h[N];

int find(int x)
{
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x)
    {
        t++;
        if (t == N)
            t = 0;
    }
    return t;
}
int main()
{
    memset(h, 0x3f, sizeof h);
    int n, x;
    char c;
    cin >> n;
    while (n--)
    {
        cin >> c >> x;
        if (c == 'I')
            h[find(x)] = x;
        else if (c == 'Q')
        {
            if (h[find(x)] == null)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}