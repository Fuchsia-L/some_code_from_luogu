#include <iostream>
using namespace std;
int a[int(1e6 + 2)] = {0};
void find(int num, int l, int r)
{
    if (l > r)
    {
        cout << "-1 ";
        return;
    }
    int mid = (l + r) / 2;
    if (a[mid] == num)
    {
        if (l == r)
        {
            cout << mid << " ";
            return;
        }
        find(num, l, mid);
        return;
    }
    if (a[mid] > num)
    {
        find(num, l, mid - 1);
    }
    else if (a[mid] < num)
    {
        find(num, mid + 1, r);
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int num;
        cin >> num;
        find(num, 1, n);
    }
    return 0;
}