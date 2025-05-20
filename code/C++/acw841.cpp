#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    string s, s1, s2;
    cin >> n >> m;
    cin >> s;
    while (m--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        s1 = s.substr(a-1, b-a+1);
        s2 = s.substr(c-1, d-c+1);
        //cout << s1 << endl << s2 << endl;
        if(s1 == s2)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}