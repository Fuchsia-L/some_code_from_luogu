#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        q.push(p);
    }
    for (int i = 1; i < n; i++)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push(a + b);
        ans += (a + b);
    }
    cout << ans;
    return 0;
}