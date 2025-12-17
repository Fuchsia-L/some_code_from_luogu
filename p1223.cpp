#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int time;
    int num;
};
bool cmp(node a, node b)
{
    if (a.time == b.time)
        return a.num < b.num;
    return a.time < b.time;
}
int main()
{
    int n;
    cin >> n;
    node a[1008];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].time;
        a[i].num = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].num << " ";
        sum += a[i].time * (n - i);
    }
    cout << endl;
    printf("%.2f", 1.00 * sum / n);
    return 0;
}