#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> p;
    for (int i = 1; i <= n; i++)
    {
        int d;
        string s;
        cin >> d >> s;
        if (d == 0)
            d = 1;
        else
            d = -1;
        p.push_back({d, s});
    }
    int point = 0;
    for (int i = 1; i <= m; i++)
    {
        int fx, num;
        cin >> fx >> num;
        if (fx == 0)
            fx = -1;
        fx = -fx;
        fx = fx * p[num].first;
        point = point + fx * num;
        if (point >= n)
            point -= n;
        if (point < 0)
            point += n;
        // cout << point << endl;
    }
    cout << p[point].second;
    return 0;
}