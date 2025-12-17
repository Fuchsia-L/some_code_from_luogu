#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main()
{
    long long n, c;
    long long ans = 0;
    cin >> n >> c;
    vector<long long> num;
    map<long long, long long> mapp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
        mapp[x]++;
    }
    for (int i = 0; i <= n - 1; i++)
    {
        ans += mapp[num[i] + c];
        // cout << i << " " << ans << endl;
    }
    cout << ans;
    return 0;
}