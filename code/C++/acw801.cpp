#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    while(n--)
    {
        int num = 0;
        cin >> x;
        while(x)
        {
            if(x % 2 == 1)
            {
                num++;
                x /= 2;
            }
            else
            {
                x /= 2;
            }
        }
        cout << num << ' ';
    }
    return 0;
}