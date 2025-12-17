#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[109] = {0};
    int ans[109][2] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans[i][0] = ans[i][1] = 1;
    }
    // cout << "ok" << endl; ////////////////
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                ans[i][0] = max(ans[i][0], ans[j][0] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] < a[i])
            {
                ans[i][1] = max(ans[i][1], ans[j][1] + 1);
            }
        }
        if (i == n)
            ans[0][0] = n - ans[i][0] - ans[i][1] + 1;
        ans[0][0] = min(ans[0][0], n - ans[i][0] - ans[i][1] + 1);
    }
    cout << ans[0][0];
    return 0;
}