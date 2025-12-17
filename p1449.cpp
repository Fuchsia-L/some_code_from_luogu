#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> num;
    string s;
    cin >> s;
    int n = 0;
    for (int i = 0; s[i] != '@'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            n = n * 10 + int(s[i] - '0');
        else if (s[i] == '.')
        {
            num.push(n);
            n = 0;
        }
        else
        {
            int fir = num.top();
            num.pop();
            int sec = num.top();
            num.pop();
            if (s[i] == '+')
            {
                num.push(fir + sec);
            }
            else if (s[i] == '-')
            {
                num.push(sec - fir);
            }
            else if (s[i] == '*')
            {
                num.push(sec * fir);
            }
            else if (s[i] == '/')
            {
                num.push(sec / fir);
            }
        }
    }
    cout << num.top() << endl;
    return 0;
}