#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int e[N], l[N], r[N], idx;

// 0和1是左右头节点
void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 在第k个节点右侧插入x
void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}

void del(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

void print_list()
{
    for(int i = r[0]; i != 1; i = r[i])
    {
        cout << e[i] << ' ';
    }
}

int main()
{
    int m, k, x;
    cin >> m;
    init();
    while(m--)
    {
        string s;
        cin >> s;
        if(s == "L")
        {
            cin >> x;
            insert(0, x);
        }
        else if(s == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if(s == "D")
        {
            cin >> x;
            del(x+1);
        }
        else if(s == "IL")
        {
            cin >> k >> x;
            insert(l[k+1], x);
        }
        else if(s == "IR")
        {
            cin >> k >> x;
            insert(k+1, x);
        }
    }
    print_list();
    return 0;
}