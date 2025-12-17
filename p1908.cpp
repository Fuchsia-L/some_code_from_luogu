#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a[800009], n;
long long ans = 0;
int temp[800009];
void sortt(int l, int r)
{
    // cout << l << " " << r << endl;
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    sortt(l, mid);
    sortt(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j])
        {
            ans += mid - i + 1;
            temp[k++] = a[j++];
        }
        else
        {
            temp[k++] = a[i++];
        }
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = temp[i];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sortt(1, n);
    cout << ans;
}