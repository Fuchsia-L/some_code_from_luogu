#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> woods;

bool pd(int h, int m, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (woods[i] > h)
            sum += woods[i] - h;
        if (sum >= m)
            return true;
    }
    return false;
}
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        woods.push_back(x);
        r = max(r, x);
    }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (pd(mid, m, n))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}