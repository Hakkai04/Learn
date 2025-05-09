#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n;
int a[N];
int tmp[N];
long long ans;

void m_sort(int a[], int l, int r)
{
    if(l >= r)return;
    
    int mid = (l+r)/2;
    m_sort(a, l, mid);
    m_sort(a, mid+1, r);
    
    int i = l;
    int j = mid+1;
    int idx = 0;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j])tmp[idx++] = a[i++];
        else
        {
            tmp[idx++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while(i <= mid)tmp[idx++] = a[i++];
    while(j <= r)tmp[idx++] = a[j++];
    for(int k = 0; k < idx; k++)a[k+l] = tmp[k];
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    m_sort(a, 0, n-1);
    cout << ans;
    return 0;
}