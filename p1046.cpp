#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int ans = 0, tt;
    int h[19] = {0};
    for (int i = 1; i <= 10; i++)
    {
        cin >> h[i];
        h[i] -= 30;
    }
    cin >> tt;
    for (int i = 1; i <= 10; i++)
    {
        if (h[i] <= tt)
            ans++;
    }
    cout << ans;
    return 0;
}