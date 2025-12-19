#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <climits>
using namespace std;

struct uuu
{
    int val, ai, bi;
    bool operator>(const uuu &other) const
    {
        return this->val > other.val;
    }
};
int n;
vector<int> a, b;
priority_queue<uuu, vector<uuu>, greater<uuu>> check;
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
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        check.push({a[i] + b[0], i, 0});
    }
    while (sum < n)
    {
        uuu now = check.top();
        check.pop();
        cout << now.val << " ";
        if (now.bi + 1 < n)
            check.push({a[now.ai] + b[now.bi + 1], now.ai, now.bi + 1});
        sum++;
    }
    return 0;
}