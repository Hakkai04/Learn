#include <bits/stdc++.h>
using namespace std;

stack<char> op;
stack<int> num;
map<char, int> mp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval()
{
    int b = num.top();num.pop();
    int a = num.top();num.pop();
    char c = op.top();op.pop();
    int x;
    if(c == '+')x = a + b;
    if(c == '-')x = a - b;
    if(c == '*')x = a * b;
    if(c == '/')x = a / b;
    num.push(x);
}

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if(isdigit(c))
        {
            int x = 0, j = i;
            while(j < s.size() && isdigit(s[j]))x = x * 10 + s[j++] - '0';
            i = j - 1;
            num.push(x);
        }
        else if(c == '(')op.push(c);
        else if(c == ')')
        {
            while(op.top() != '(')eval();
            op.pop();
        }
        else
        {
            while(!op.empty() && op.top() != '(' && mp[op.top()] >= mp[c])eval();
            op.push(c);
        }
    }
    while(!op.empty())eval();
    cout << num.top();
    return 0;
}