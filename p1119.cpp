#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int city[205];
int dis[205][205];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> city[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dis[i][j] = INF;
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    int Q;
    cin >> Q;
    int k = 0;

    while (Q--)
    {
        int x, y, t;
        cin >> x >> y >> t;

        // 【核心】：利用单调性，接着上次的进度继续更新
        // 只有当 city[k] <= t 时，说明第 k 个村庄修好了，可以用来做中转点了
        while (k < n && city[k] <= t)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dis[i][k] != INF && dis[k][j] != INF)
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
            k++; // 这个村庄处理完了，看下一个
        }
        if (city[x] > t || city[y] > t || dis[x][y] == INF)
            cout << -1 << endl;
        else
            cout << dis[x][y] << endl;
    }
    return 0;
}