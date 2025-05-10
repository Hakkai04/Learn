#include <bits/stdc++.h>
using namespace std;
typedef double db;

db search_(db l, db r, db x)
{
    const db eps = 1e-8;
    while(r - l > eps)
    {
        db mid = (l + r) / 2.0;
        if(x <= mid*mid*mid)r = mid;
        else l = mid;
    }
    return l;
}

int main()
{
    db n;
    cin >> n;
    printf("%.6lf", search_(-100.0, 100.0, n));
    return 0;
}