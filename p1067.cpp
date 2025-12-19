#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, f = 1;
    cin >> n;
    while (n >= 0)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            n--;
            continue;
        }
        if (a > 0)
        {
            if (f != 1)
                cout << "+";
        }
        else
            cout << "-";
        f = 0;
        a = abs(a);
        if (n != 0 && n != 1)
        {
            if (a != 1)
                cout << a;
            cout << "x^" << n;
        }
        else if (n == 1)
        {
            if (a != 1)
                cout << a;
            cout << "x";
        }
        else
            cout << a;
        n--;
    }
    return 0;
}