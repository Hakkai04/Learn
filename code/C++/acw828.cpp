#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int st[N];
int idx = 0;

void push(int x)
{
    st[idx++] = x;
}

void pop()
{
    idx--;
}

void empty()
{
    if(idx == 0)cout << "YES" << endl;
    else cout << "NO" << endl;
}

void query()
{
    cout << st[idx-1] << endl;
}

int main()
{
    int m;
    cin >> m;
    int x;
    string s;
    while(m--)
    {
        cin >> s;
        if(s == "push")
        {
            cin >> x;
            push(x);
        }
        else if(s == "pop")pop();
        else if(s == "empty")empty();
        else if(s == "query")query();
    }
    return 0;
}