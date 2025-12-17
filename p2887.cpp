#include <iostream>
#include <algorithm>
using namespace std;
struct cow
{
    int x;
    int y;
};
bool cmp(cow a, cow b)
{
    return a.x > b.x;
}
int main()
{
    cow cows[2505];
    int fs[3005] = {0};
    int c, l;
    cin >> c >> l;
    for (int i = 1; i <= c; i++)
    {
        cin >> cows[i].x >> cows[i].y;
    }
    sort(cows + 1, cows + c + 1, cmp);
    for (int i = 1; i <= l; i++)
    {
        int x;
        cin >> x;
        cin >> fs[x];
    }
    int now = 1, ans = 0;
    for (int i = 1; i <= 3004; i++)
    {
        if (now > c)
        {
            break;
        }
        while (fs[i] != 0)
        {
            if (now > c)
            {
                break;
            }
            if (cows[now].x <= i && cows[now].y >= i)
            {
                ans++;
                now++;
                fs[i]--;
            }
            if (cows[now].y < i)
            {
                break;
            }
            if (cows[now].x > i)
            {
                now++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}