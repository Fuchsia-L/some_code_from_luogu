#include <iostream>
using namespace std;
int main()
{
    int n, maxx = 1;
    int ans[5005];
    cin >> n;
    int a[5002];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
                ans[i] = max(ans[i], ans[j] + 1);
        }
        maxx = max(ans[i], maxx);
    }
    cout << maxx;
    return 0;
}