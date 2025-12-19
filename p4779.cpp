#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long maxn = 1e5 + 2;
ll vis[maxn];
struct node
{
    ll v, w;
    bool operator>(const node &other) const
    {
        return this->w > other.w;
    }
};
vector<node> path[maxn];
ll n, m, s;
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        path[u].push_back({v, w});
    }
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 1e9 + 1;
    }
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({s, 0});
    vis[s] = 0;
    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        if (vis[now.v] != now.w)
            continue;
        for (node towhere : path[now.v])
        {
            if (towhere.w + now.w < vis[towhere.v])
            {
                vis[towhere.v] = towhere.w + now.w;
                pq.push({towhere.v, vis[towhere.v]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << vis[i] << " ";
    }
    return 0;
}