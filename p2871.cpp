#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int bag[12809] = {0};
    for (int i = 1; i <= n; i++)
    {
        int w, v;
        cin >> w >> v;
        for (int j = m; j >= w; j--)
        {
            bag[j] = max(bag[j], bag[j - w] + v);
        }
    }
    cout << bag[m] << endl;
    return 0;
}