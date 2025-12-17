#include <iostream>
using namespace std;
int book[12] = {0}, n, anssum = 0;
int ans[19] = {0};
bool pd(int nx, int ny)
{
    for (int i = 1; i < nx; i++)
    {
        int x = i, y = ans[i];
        float f = 1.00 * (x - nx) / (y - ny);
        if (f == 1 || f == -1)
            return false;
    }
    return true;
}
void putt(int now)
{
    if (now == n + 1)
    {
        anssum++;
        if (anssum <= 3)
        {
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (book[i] == 0 && pd(now, i))
        {
            book[i] = 1;
            ans[now] = i;
            putt(now + 1);
            book[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    putt(1);
    cout << anssum;
    return 0;
}