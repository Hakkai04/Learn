#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
map<string, int> mp;
queue<string> q;
ii ce[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    string s;
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    q.push(s);
    mp[s] = 1;

    while (!q.empty())
    {
        s = q.front();
        q.pop();
        //cout << s << endl;
        if(s == "12345678x")
        {
            cout << mp[s] - 1;
            return 0;
        }

        int pos;
        for (pos = 0; pos <= 8; pos++)
            if (s[pos] == 'x')
                break;
        int xp = pos / 3;
        int yp = pos % 3;
        for (int i = 0; i <= 3; i++)
        {
            int x = xp + ce[i].first;
            int y = yp + ce[i].second;
            if (x < 0 || x > 2 || y < 0 || y > 2)
                continue;
            int rep = x * 3 + y;
            string ss = s;
            swap(ss[pos], ss[rep]);
            if(!mp[ss])
            {
                //cout <<s << ' ' << mp[s] << ' ' <<  ss << ' '<< mp[ss] << endl;
                mp[ss] = mp[s] + 1;
                q.push(ss);
            }
        }
        //cout << endl; 
    }
    cout << -1;
    return 0;
}