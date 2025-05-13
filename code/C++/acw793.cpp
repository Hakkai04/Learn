#include <bits/stdc++.h>
using namespace std;

vector<int> A, C;
int b;

vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || t; i++)
    {
        if (i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

int main()
{
    string s;
    cin >> s >> b;
    for (int i = s.size() - 1; i >= 0; i--)
        A.push_back(s[i] - '0');
    C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}