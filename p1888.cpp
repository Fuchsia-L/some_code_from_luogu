#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int maxx = max(a, max(b, c));
    int minn = min(a, min(b, c));
    int x = gcd(maxx, minn);
    cout << minn / x << "/" << maxx / x;
    return 0;
}