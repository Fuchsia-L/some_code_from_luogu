#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    int m, l, wo, book[1002] = {0}, ans = 0;
    cin >> m >> l;
    while (l--)
    {
        cin >> wo;
        if (book[wo])
            continue;
        ans++;
        if (q.size() < m)
        {
            q.push(wo);
            book[wo] = 1;
        }
        else
        {
            book[q.front()] = 0;
            q.pop();
            q.push(wo);
            book[wo] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}