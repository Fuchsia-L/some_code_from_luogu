#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char s = 0, value = 0;
    int ans[200] = {0};
    while (scanf("%c:=%c;", &s, &value) == 2)
    {
        if (value == 'a' || value == 'b' || value == 'c')
        {
            ans[int(s)] = ans[int(value)];
        }
        else
            ans[int(s)] = int(value - '0');
    }
    cout << ans[int('a')] << " " << ans[int('b')] << " " << ans[int('c')] << endl;
    return 0;
}