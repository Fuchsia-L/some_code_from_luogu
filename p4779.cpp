#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // first 是距离//

bool vis[int(1e5)];
int dist[int(1e5)];
int INF = INT_MAX;

priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> adj[int(1e5)];

int n, m, s;

void start()
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        dist[i] = INF;
    }
    dist[s] = 0;
}

int main()
{
    cin >> n >> m >> s;
    start();
    pq.push({0, s});
    for (int i = 1; i <= m; i++)
    {
        int st, ed, le;
        cin >> st >> ed >> le;
        adj[st].push_back({le, ed});
    }
    while (!pq.empty())
    {
        pii now = pq.top();
        pq.pop();
        if (vis[now.second])
            continue;
        vis[now.second] = true;
        for (auto it = adj[now.second].begin(); it != adj[now.second].end(); it++)
        {
            int w2 = it->first + now.first;
            if (dist[it->second] > w2)
            {
                pq.push({w2, it->second});
                dist[it->second] = w2;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}