#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
stack<int> st;

int main()
{
    int n, x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        while(!st.empty() && st.top() >= x)st.pop();
        if(!st.empty())cout << st.top() << ' ';
        else cout << -1 << ' ';
        st.push(x);
    }
    return 0;
}
