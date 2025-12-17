#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, s, a, h, num = 0;
    cin >> n >> s >> a >> h;
    h += a;
    int all[102] = {0};
    for (int i = 1; i <= n; i++)
    {
        int x, ss;
        cin >> x >> ss;
        if (x <= h)
            all[++num] = ss;
    }
    sort(all + 1, all + num + 1);
    int ans = 0;
    for (int i = 1; i <= num; i++)
    {
        if (s >= all[i])
        {
            s -= all[i];
            ans++;
        }
        else
            break;
    }
    cout << ans << endl;
    return 0;
}