#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
// h[k]堆,ph[k]第k个插入的点在堆中位置,hp[k]堆中k位置是第几个插入的点
// idx第几个插入的点， num堆中点个数
int h[N], hp[N], ph[N], idx, num;

void heap_swap(int x, int y)
{
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}

void up(int x)
{
    if (x == 1)
        return;
    if (h[x / 2] > h[x])
    {
        heap_swap(x / 2, x);
        up(x / 2);
    }
}

void down(int x)
{
    int t = x;
    if(2 * x <= num && h[t] > h[2 * x])t = 2 * x;
    if(2 * x + 1 <= num && h[t] > h[2 * x + 1])t = 2 * x + 1;
    if(t != x)
    {
        heap_swap(t, x);
        down(t);
    }
}

void I(int x)
{
    num++;
    idx++;
    ph[idx] = num;
    hp[num] = idx;
    h[num] = x;
    up(num);
}

void PM()
{
    cout << h[1] << endl;
}

void DM()
{
    heap_swap(1, num);
    num--;
    down(1);
}

void D(int k)
{
    k = ph[k];
    heap_swap(k, num);
    num--;
    up(k);
    down(k);
}

void C(int k, int x)
{
    k = ph[k];
    h[k] = x;
    up(k);
    down(k);
}

int main()
{
    int n, x, k;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "I")
        {
            cin >> x;
            I(x);
        }
        if (s == "PM")
            PM();
        if (s == "DM")
            DM();
        if (s == "D")
        {
            cin >> k;
            D(k);
        }
        if (s == "C")
        {
            cin >> k >> x;
            C(k, x);
        }
    }
    return 0;
}
