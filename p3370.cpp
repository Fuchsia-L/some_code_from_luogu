#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<string> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string ss;
        cin >> ss;
        s.insert(ss);
    }
    cout << s.size();
    return 0;
}