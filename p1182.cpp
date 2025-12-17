#include <iostream>
using namespace std;
int a[100000] = {0}, m, n;
bool pd(int num)
{
    int fd = 1, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << "第->" << i << endl;
        if (sum + a[i] > num)
        {
            cout << "no" << endl;
            fd++;
            sum = a[i];
            if (fd > m)
                return false;
        }
        else
        {
            cout << sum + a[i] << "ok" << endl;
            sum += a[i];
        }
    }
    return true;
}
int main()
{
    int ans = 0, fu = -1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
        fu = max(fu, a[i]);
    }
    int left = fu, right = ans;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (pd(mid))
        {
            cout << "mid->" << mid << endl;
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}