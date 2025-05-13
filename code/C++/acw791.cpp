#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> A, B, C;

vector<int> add(vector<int> &a, vector<int> &b)
{
    if (a.size() < b.size())
        return add(b, a);
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i];
        if (i < b.size())
            t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t)
        c.push_back(t);
    return c;
}

int main()
{
    string s;
    getline(cin, s);
    for (int i = s.size() - 1; i >= 0; i--)
        A.push_back(s[i] - '0');
    getline(cin, s);
    for (int i = s.size() - 1; i >= 0; i--)
        B.push_back(s[i] - '0');
    C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}