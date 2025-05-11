#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
// head链表头， e[]存储节点值, ne[]存储节点的next指针, idx当前节点
int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

void insert_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void insert_k(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void del(int x)
{
    ne[x] = ne[ne[x]];
}

void print()
{
    for(int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
}

int main()
{
    int n;
    char c;
    int k, x;
    cin >> n;
    init();

    while(n--)
    {
        cin >> c;
        if(c == 'H')
        {
            cin >> x;
            insert_head(x);
        }
        else if(c == 'D')
        {
            cin >> x;
            if(!x)head = ne[head];
            else del(x - 1);
        }
        else if(c == 'I')
        {
            cin >> k >> x;
            insert_k(k - 1,x);
        }
    }
    print();
    return 0;
}