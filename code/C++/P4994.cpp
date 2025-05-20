#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    int a = 1, b = 1, c;
    if (1 % m == 0 && 2 % m == 1)
    {
        cout << 2;
        return 0;
    }
    if(2%m == 0 && 3 % m == 1)
    {
        cout << 3;
        return 0;
    }
    for (int n = 3;; n++)
    {
        c = a + b;
        if ((c - 1) % m == 0)
        {
            if ((b + c) % m == 0)
            {
                cout << n + 1;
                return 0;
            }
        }
        a = b;
        b = c;
    }
    return 0;
}