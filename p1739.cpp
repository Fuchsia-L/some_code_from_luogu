#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> ans;
    for (int i = 0; s[i] != '@'; i++)
    {
        if (s[i] == '(')
            ans.push('(');
        else if (s[i] == ')')
        {
            if (ans.empty())
            {
                cout << "NO" << endl;
                return 0;
            }
            else
                ans.pop();
        }
    }
    if (ans.empty())
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}