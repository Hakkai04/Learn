#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int a[N];

// 找左边界
int search_l(int l, int r, int x)
{
    while(l < r)
    {
        int mid = l + r >> 1;
        if(a[mid] >= x)r = mid;
        else l = mid +1;
    }
    if(a[l] != x)return -1;
    return l;
}

// 找右边界
int search_r(int l, int r, int x)
{
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(a[mid] <= x)l = mid;
        else r = mid - 1;
    }
    if(a[l] != x)return -1;
    return l;
}

int main()
{
    int n, q, x;
    cin >> n >> q;
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    while(q--)
    {
        cin >> x;
        cout << search_l(0, n-1, x) << ' ' << search_r(0, n-1, x) << endl;
    }
    return 0;
}