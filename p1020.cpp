#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    vector<int> h;
    int x;
    while (cin >> x)
    {
        h.push_back(x);
    }
    vector<int> ans;
    for (int i = 0; i < h.size(); i++)
    {
        if (ans.empty() || ans.back() >= h[i])
            ans.push_back(h[i]);
        else
        {
            auto it = upper_bound(ans.begin(), ans.end(), h[i], greater<int>());
            *it = h[i];
        }
    }
    cout << ans.size() << endl;
    vector<int> ans2;
    for (int i = 0; i < h.size(); i++)
    {
        if (ans2.empty() || ans2.back() < h[i])
            ans2.push_back(h[i]);
        else
        {
            auto it = lower_bound(ans2.begin(), ans2.end(), h[i]);
            *it = h[i];
        }
    }
    cout << ans2.size();
    return 0;
}
// vector<int> lanjie(vector<int> h)
// {
//     vector<int> ans(h.size(), 1);
//     vector<int> link(h.size(), -1);
//     int maxx = 0, m = 0;
//     for (int i = 0; i < h.size(); i++)
//     {
//         link[i] = i;
//         for (int j = 0; j < i; j++)
//         {
//             if (h[j] >= h[i])
//             {
//                 if (ans[i] < ans[j] + 1)
//                 {
//                     ans[i] = max(ans[i], ans[j] + 1);
//                     link[i] = j;
//                 }
//             }
//         }
//         if (maxx < ans[i])
//         {
//             maxx = ans[i];
//             m = i;
//         }
//     }
//     for (int i = m; link[i] != i; i = link[i])
//     {
//         h.erase(h.begin() + i);
//         if (link[link[i]] == link[i])
//             h.erase(h.begin() + link[i]);
//     }
//     return h;
// }
// int main()
// {
//     int x;
//     while ((cin >> x))
//     {
//         h.push_back(x);
//     }
//     vector<int> h2 = lanjie(h);
//     cout << h.size() - h2.size() << endl;
//     int sum = 1;
//     while (h2.size() != 0)
//     {
//         h2 = lanjie(h2);
//         sum++;
//     }
//     cout << sum << endl;
//     return 0;
// }