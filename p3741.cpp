#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0, f = 0, ff = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            ans++;
            s[i] = s[i + 1] = 'o';
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != 'o' && s[i + 1] != 'o')
        {
            if (s[i] == 'K' && s[i + 1] == 'V')
                continue;
            f++;
            break;
        }
    }
    cout << ans + f << endl;
    return 0;
}