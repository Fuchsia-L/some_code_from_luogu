#include <bits/stdc++.h>
using namespace std;
struct node
{
    int start, end;
};
node a[1000009];
bool cmp(node a, node b)
{
    return a.end < b.end;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].start >> a[i].end;
    }
    sort(a + 1, a + 1 + n, cmp);
    int ed = n, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            ans++;
            ed = a[i].end;
            continue;
        }
        if (a[i].start >= ed)
        {
            ed = a[i].end;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}