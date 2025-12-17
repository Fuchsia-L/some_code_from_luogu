#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, ans = 0;
    cin >> x >> y;
    for (int i = x; i <= y; i++)
    {
        int j = x * y / i;
        if (gcd(i, j) == x && lcm(i, j) == y)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}