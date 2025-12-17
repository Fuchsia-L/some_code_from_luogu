#include <iostream>
using namespace std;
int main()
{
    int n;
    double ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        double a, b;
        cin >> a >> b;
        ans += a * b;
    }
    cout << ans;
    return 0;
}