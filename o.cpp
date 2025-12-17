#include <iostream>
#include <vector>
#include <queue>
#include <climits> // 用于 INT_MAX

using namespace std;

const int INF = INT_MAX; // 无穷大
const int N = 100005;    // 根据题目要求调整最大点数

// 存边的结构：{目标点, 权值}
// 也可以写 struct，但 pair 写起来快
typedef pair<int, int> PII;

// 邻接表：adj[u] 存的是从 u 出发能到的所有点和边权
vector<PII> adj[N];

int dist[N]; // 存起点到各点的最短距离
bool vis[N]; // 标记是否已经确定了最短路

int n, m, s; // n个点，m条边，s是起点

void dijkstra(int start)
{
    // 1. 初始化
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    for (int i = 1; i <= n; i++)
        vis[i] = false;

    dist[start] = 0;

    // 定义小根堆：类型是 PII，底层容器 vector，排序规则 greater (从小到大)
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    // 把起点扔进去：{距离0, 起点s}
    pq.push({0, start});

    while (!pq.empty())
    {
        // 2. 贪心：取出当前距离最近的点
        auto top = pq.top();
        pq.pop();

        int d = top.first;  // 当前路径长度
        int u = top.second; // 当前点

        // 如果这个点已经处理过（是旧的冗余数据），就跳过
        if (vis[u])
            continue;
        vis[u] = true; // 标记为已访问

        // 3. 松弛：扫描所有邻居
        // auto v_pair 也是一个 pair<int, int>，代表 {邻居v, 边权w}
        for (auto v_pair : adj[u])
        {
            int v = v_pair.first;
            int w = v_pair.second;

            // 如果找到了更短的路
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                // 更新后，把新的距离扔进堆里
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    // 读入优化（竞赛常用）
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // 有向图
        // 如果是无向图，记得加上：adj[v].push_back({u, w});
    }

    dijkstra(s);

    // 输出结果
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << (1LL << 31) - 1 << " "; // 洛谷某些题要求无法到达输出特定值
        else
            cout << dist[i] << " ";
    }

    return 0;
}