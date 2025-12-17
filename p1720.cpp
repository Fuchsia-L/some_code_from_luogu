#include <iostream>
using namespace std;
int main()
{
    long long ans[55] = {0, 1, 1, 2, 3};
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
        ans[i] = ans[i - 1] + ans[i - 2];
    printf("%.2f", float(ans[n]));
    return 0;
}