#include <bits/stdc++.h>
using namespace std;

const int N = 20;

bool row[N], col[N], cl[N], lc[N];
bool board[N][N];
int n;

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == false)
                cout << '.';
            else
                cout << 'Q';
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int x)
{
    if (x == n)
        print();
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !cl[x + i] && !lc[x + n - i])
        {
            board[x][i] = true;
            col[i] = true;
            cl[x + i] = true;
            lc[x + n - i] = true;
            dfs(x + 1);
            board[x][i] = false;
            col[i] = false;
            cl[x + i] = false;
            lc[x + n - i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}