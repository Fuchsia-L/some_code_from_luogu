#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int>>> g[2550];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        g[u].push_back({w, v});
    }
    priority_queue<pair<int, int>> pq;
    vector<int> book[2550];
    for (int i = 1; i <= n; i++)
        book[i] = 0x3f3f3f3f;
    pq.push({0, s});
    book[s] = 0;
    while (!pq.empty())
    {
        auto [wi, ui] = pq.top();
        pq.pop();
        if (book[ui] < wi)
            continue;
        for (auto next : g[ui])
        {
            if (next.first + wi < book[next.second])
            {
                book[next.second] = next.first + wi;
                pq.push({next.first + wi, next.second});
            }
        }
    }
    cout << book[t];
    return 0;
}