#include<bits/stdc++.h>
using namespace std;

vector<int> A, C;
int b;

vector<int> div(vector<int> &a, int &b, int &t)
{
    vector<int> c;
    t = 0;
    for(int i = 0; i < a.size(); i++)
    {
        t = t * 10 + a[i];
        c.push_back(t/b);
        t%=b;
    }
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back() == 0)c.pop_back();
    return c;
}

int main()
{
    string s;
    int t;
    cin >> s >> b;
    for(int i = 0; i < s.size(); i++)A.push_back(s[i] - '0');
    C = div(A, b, t);
    for(int i = C.size() - 1; i >= 0; i--)cout << C[i];
    cout << endl << t;
}