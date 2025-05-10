#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
int n, k;
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    sort(a, a+n);
    cout << a[k-1];
    return 0;
}