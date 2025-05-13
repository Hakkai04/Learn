#include <bits/stdc++.h>
using namespace std;

vector<int> A, B, C;

bool cmp(vector<int> &a, vector<int> &b)
{
    if(a.size() != b.size())return a.size() > b.size();
    for(int i = a.size() - 1; i >= 0; i--)
    {
        if(a[i] != b[i])return a[i] > b[i];
        else continue;
    }
    return true;
}

vector<int> sub(vector<int> &a, vector<int> &b)
{
    if(!cmp(a, b))return sub(b, a);
    
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if(i < b.size())t -= b[i];
        c.push_back((t+10)%10);
        if(t < 0)t = 1;
        else t = 0;
    }

    while(c.size() > 1 && c.back() == 0)c.pop_back();
    return c;
}

int main()
{
    string s;
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--)A.push_back(s[i] - '0');
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--)B.push_back(s[i] - '0');
    C = sub(A, B);
    if(!cmp(A, B))cout << '-';
    for(int i = C.size() - 1; i >= 0; i--)cout << C[i];
    cout << endl;
    return 0;
}
