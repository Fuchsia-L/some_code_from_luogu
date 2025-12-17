#include <iostream>
using namespace std;
int main()
{
    int n, c;
    cin >> n;
    string s;
    cin >> s;
    while (n--)
    {
        cin >> c;
        if (c == 1)
        {
            string t;
            cin >> t;
            s += t;
            cout << s << endl;
        }
        else if (c == 2)
        {
            int start, len;
            string ns = "";
            cin >> start >> len;
            while (len-- && s[start] != '\0')
            {
                ns += s[start];
                start++;
            }
            s = ns;
            cout << s << endl;
        }
        else if (c == 3)
        {
            int l;
            string t, ns;
            cin >> l >> t;
            for (int i = 0; i < l; i++)
                ns += s[i];
            ns += t;
            for (int i = l; s[i] != '\0'; i++)
            {
                ns += s[i];
            }
            s = ns;
            cout << s << endl;
        }
        else if (c == 4)
        {
            string t;
            cin >> t;
            int f = -1;
            for (int i = 0; s[i] != '\0'; i++)
            {
                if (s[i] == t[0])
                    for (int ii = i, j = 0; t[j] != '\0'; j++, ii++)
                    {
                        if (s[ii] != t[j])
                        {
                            break;
                        }
                        if (t[j + 1] == '\0')
                        {
                            f = i;
                        }
                    }
                if (f != -1)
                    break;
            }
            cout << f << endl;
        }
    }
    return 0;
}