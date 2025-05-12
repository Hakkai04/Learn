#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int q[N], hh = 0, tt = -1;

void push(int x)
{
    q[++tt] = x;
}

void pop()
{
    hh++;
}

void query()
{
    cout << q[hh] << endl;
}

void empty()
{
    if(hh  <= tt)cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        string s;
        cin >> s;
        if(s == "push")
        {
            int a;
            cin >> a;
            push(a);
        }
        if(s == "pop")pop();
        if(s == "empty")empty();
        if(s == "query")query();
    }
    return 0;
}