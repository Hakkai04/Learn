#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int son[N][26], idx, cnt[N];

void insert(string &s)
{
    int p = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

void query(string &s)
{
    int p = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if(!son[p][u])
        {
            cout << 0 << endl;
            return;
        }
        p = son[p][u];
    }
    cout << cnt[p] << endl;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        char c;
        string s;
        cin >> c >> s;
        if(c == 'I')
        {
            insert(s);
        }
        else if(c == 'Q')
        {
            query(s);
        }
    }
    return 0;
}