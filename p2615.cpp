#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[44][44];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
    a[1][n / 2 + 1] = 1;
    int x = 1, y = n / 2 + 1;
    for (int i = 2; i <= n * n; i++)
    {
        if (x == 1 && y != n)
        {
            x = n;
            y = y + 1;
            a[x][y] = i;
        }
        else if (y == n && x != 1)
        {
            y = 1;
            x = x - 1;
            a[x][y] = i;
        }
        else if (x == 1 && y == n)
        {
            x++;
            a[x][y] = i;
        }
        else if (a[x - 1][y + 1] == 0)
        {
            x = x - 1;
            y++;
            a[x][y] = i;
        }
        else
        {
            x++;
            a[x][y] = i;
        }
        // cout << x << " " << y << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}