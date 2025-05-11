#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N];
bool exist[N];
int res;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);

    for(int i = 0 , j = 0; i < n;i++)
    {
        if(exist[a[i]] == true)
        {
            for(int k = j; k <= i; k++)
            {
                exist[a[k]] = false;
                if(a[k] == a[i])
                {
                    j = k+1;
                    break;
                }
            }
            exist[a[i]] = true;
        }
        else
        {
            exist[a[i]] = true;
            res = max(i-j+1, res);
        }
    }
    cout << res;
    return 0;
}