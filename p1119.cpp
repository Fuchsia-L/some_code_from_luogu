#include <bits/stdc++.h>
using namespace std;
int n, m, city[202], bk = 0;
int dis[202][202];
int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n - 1; i++)
        cin >> city[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dis[i][j] = INT_MAX / 2;
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
        dis[v][u] = w;
    }
    cin >> m;
    int x, y, t;
    for (int i = 1; i <= m; i++)
    {
        int k = 0;
        cin >> x >> y >> t;
        for (k = 0; k < n; k++)
        {
            if (city[k] > t)
                continue;
            for (int i = 0; i < n; i++)
            {
                if (city[i] > t)
                    continue;
                for (int j = 0; j < n; j++)
                {
                    if (city[j] > t)
                        continue;
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    dis[j][i] = dis[i][j];
                }
            }
        }
        if (dis[x][y] >= INT_MAX / 2 || city[x] > t || city[y] > t)
            cout << -1 << endl;
        else
            cout << dis[x][y] << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// int n, m, city[202];
// int citybook[202] = {0}, book[202];
// vector<pair<int, int>> g[202];
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
// void dj(int s, int t)
// {
//     for (int i = 0; i <= n - 1; i++)
//     {
//         book[i] = INT_MAX;
//         if (t >= city[i])
//             citybook[i] = 1;
//     }
//     if (citybook[s] == 0)
//         return;
//     book[s] = 0;
//     pq.push({0, s});
//     while (!pq.empty())
//     {
//         auto [wi, ui] = pq.top();
//         pq.pop();
//         if (book[ui] < wi)
//             continue;
//         for (auto next : g[ui])
//         {
//             if ((book[next.second] > wi + next.first) && citybook[next.second] == 1)
//             {
//                 book[next.second] = wi + next.first;
//                 pq.push({wi + next.first, next.second});
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i <= n - 1; i++)
//         cin >> city[i];
//     for (int i = 1; i <= m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({w, v});
//         g[v].push_back({w, u});
//     }
//     cin >> m;
//     int x, y, t;
//     for (int i = 1; i <= m; i++)
//     {
//         cin >> x >> y >> t;
//         dj(x, t);
//         if (book[y] == INT_MAX)
//             cout << -1 << endl;
//         else
//             cout << book[y] << endl;
//     }
//     return 0;
// }