#include <iostream>
using namespace std;
int m, n, ans = 0;
char a[109][109];
void findw(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return;
    int d[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
    for (int i = 0; i <= 7; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (a[nx][ny] == 'W')
        {
            a[nx][ny] = '.';
            findw(nx, ny);
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'W')
            {
                findw(i, j);
                ans++;
                //    cout << i << " " << j << endl;
            }
    }
    cout << ans;
    return 0;
}