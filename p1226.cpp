#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, m;
    cin >> a >> b >> m;
    cout << a << "^" << b << " mod " << m << "=";
    long long res = 1 % m;
    while (b)
    {
        if (b & 1)
            res = a * res % m;
        a = a * a % m;
        b >>= 1;
    }
    cout << res;
    return 0;
}