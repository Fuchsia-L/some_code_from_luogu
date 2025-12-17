#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, int>>> g1;
vector<vector<pair<int, int>>> g2;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
vector<long long> a;

void dj(int s, vector<vector<pair<int, int>>> &g)
{
    for (int i = 1; i <= n; i++)
        a[i] = 1e18;
    a[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        pair<int, int> now = q.top();
        q.pop();
        if (now.first > a[now.second])
            continue;
        for (auto next : g[now.second])
        {
            if (a[next.second] > now.first + next.first)
            {
                a[next.second] = now.first + next.first;
                q.push({now.first + next.first, next.second});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    a.resize(n + 1);
    g1.resize(n + 1);
    g2.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int st, ed, wi;
        cin >> st >> ed >> wi;
        g1[st].push_back({wi, ed});
        g2[ed].push_back({wi, st});
    }
    long long ans = 0;
    dj(1, g1);
    for (int i = 1; i <= n; i++)
        ans += a[i];
    dj(1, g2);
    for (int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans;
    return 0;
}