#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, ans = 0, a[50009], find[70] = {-1, -1, -1, -1, -1, -1, -1};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = (a[i] + a[i - 1]) % 7;
        if (find[a[i]] == -1)
            find[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (find[a[i]] != -1)
            ans = max(ans, i - find[a[i]]);
    }
    cout << ans;
}