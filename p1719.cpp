#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int a[122][122], n, ans = -99999;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int b[122];
            int maxx = -999;
            for (int k = 1; k <= n; k++)
            {
                b[k] = a[j][k] - a[i - 1][k];
                b[k] = max(b[k], b[k] + b[k - 1]);
                ans = max(ans, b[k]);
            }
        }
    }
    cout << ans;
    return 0;
}