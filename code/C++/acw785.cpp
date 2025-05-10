#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int n;
int a[N];

void q_sort(int a[], int l, int r)
{
    if(l >= r)return;
    int i = l - 1;
    int j = r + 1;
    int mid = (i+j)/2;
    int x = a[mid];
    while(i < j)
    {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j)swap(a[i], a[j]);
    }
    q_sort(a, l, j);
    q_sort(a, j+1, r);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    q_sort(a, 0, n-1);
    for(int i = 0; i < n; i++)cout << a[i] << ' ';
    return 0;
}