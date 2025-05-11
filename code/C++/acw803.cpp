#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
typedef pair<int, int> ii;
vector<ii> vecs, res;


int main()
{
    int n;
    int l, r;
    cin >> n;
    while(n--)
    {
        cin >> l >> r;
        vecs.push_back({l, r});
    }
    sort(vecs.begin(), vecs.end());
    int st = -2e9, ed = -2e9;
    for(auto vec : vecs)
    {
        if(vec.first <= ed)
        {
            if(vec.second > ed)ed = vec.second;
            else continue;
        }
        else
        {
            if(st != -2e9)res.push_back({st, ed});
            st = vec.first;
            ed = vec.second;
        }
    }
    res.push_back({st, ed});
    cout << res.size();
    return 0;
}