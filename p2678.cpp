#include <iostream>
using namespace std;
int a[50009] = {0}, m, n;
bool pd(int num)
{
    int re = 0;
    for (int i = 0, j = 1; j <= n;)
    {
        // cout << "从" << i << "到" << j;
        if (a[j] - a[i] < num)
        {
            // cout << "挪石头" << endl;
            j++;
            re++;
            if (re > m)
                return false;
            continue;
        }
        // cout << "成功" << endl;
        i = j;
        j++;
    }
    return true;
}
int main()
{
    int l, ans;
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = l;
    n++;
    int left = 0, right = l;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        bool ff = pd(mid);
        if (ff)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        // cout << "mid=" << mid << " ff=" << ff << "<<-" << endl;
    }
    cout << ans;
    return 0;
}