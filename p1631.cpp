#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<int> a, b;
int ifuse[6][2] = {1, 1, 1, 1, 0, 0};

typedef uuu<int, int, int>; // 结果//a[]//b[]
priority_queue<uuu, vector<uuu>, greater<uuu>> ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    ans.push({a[1] + b[1], 1, 1});
    int sum = 1;
    while (sum <= n)
    {
        now = ans.top();
        int ai = now.second;
        int bi = now.third;
        int nextai = ai + 1;
        int nextbi = bi + 1;
        if ()
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         ans.push(a[i] + b[j]);
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}