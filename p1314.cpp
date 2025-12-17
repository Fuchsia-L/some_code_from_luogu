#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// long long n, m, s, pre, ans = -99, ansv = -1;
// vector<vector<long long>> st;
// vector<vector<long long>> qj;

// bool pd(long long w)
// {
//     long long sum = 0;
//     for (int i = 0; i < m; i++)
//     {
//         long long yi = 0, q = 0;
//         for (int j = qj[i][0]; j <= qj[i][1]; j++)
//         {
//             // cout << "in it!" << endl;
//             int now = st[j][0] - w;
//             if (now >= 0)
//             {
//                 q++;
//                 yi += st[j][1];
//             }
//         }
//         // cout << "__out__" << endl;
//         yi *= q;
//         // cout << "检验值" << yi << endl;
//         sum += yi;
//     }
//     // cout << "sum=" << sum << endl;
//     pre = sum - s;
//     return pre < 0;
// }

// int main()
// {
//     cin >> n >> m >> s;
//     long long l = 0, r = 0, mid;
//     for (int i = 0; i < n; i++)
//     {
//         long long x, y;
//         cin >> x >> y;
//         st.push_back({x, y});
//         r = max(r, x);
//     }
//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         qj.push_back({x - 1, y - 1});
//     }
//     while (l <= r)
//     {
//         mid = (l + r) / 2;
//         // cout << "_____ok,now mid=" << mid << endl; ////////////////////////
//         if (pd(mid))
//         {
//             r = mid - 1;
//         }
//         else
//             l = mid + 1;
//         if (ansv == -1)
//         {
//             ansv = abs(pre);
//             ans = mid;
//         }
//         if (ansv >= abs(pre))
//         {
//             ansv = abs(pre);
//             ans = mid;
//         }
//         if (pre == 0)
//         {
//             cout << 0 << endl;
//             return 0;
//         }
//         // cout << "  pre=" << pre << endl;
//     }
//     cout << ansv;
//     return 0;
// }