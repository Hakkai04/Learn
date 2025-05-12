#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int a[N];
deque<int> q;

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    
    for(int i = 0; i < n; i++)
    {
        while(!q.empty() && q.back() > a[i])q.pop_back();
        q.push_back(a[i]);
        if(i - k >= 0 && q.front() == a[i-k])q.pop_front();
        if(i >= k - 1)cout << q.front() << ' ';
    }
    cout << endl;
    q.clear();
    for(int i = 0; i < n; i++)
    {
        while(!q.empty() && q.back() < a[i])q.pop_back();
        q.push_back(a[i]);
        if(i - k >= 0 && q.front() == a[i-k])q.pop_front();
        if(i >= k - 1)cout << q.front() << ' ';
    }
    return 0;
}