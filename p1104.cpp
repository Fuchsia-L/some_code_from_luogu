#include <iostream>
#include <algorithm>
using namespace std;
struct pp
{
    string name;
    int y, m, d, id;
};
bool cmp(pp p1, pp p2)
{
    if (p1.y != p2.y)
        return p1.y < p2.y;
    if (p1.m != p2.m)
        return p1.m < p2.m;
    if (p1.d != p2.d)
        return p1.d < p2.d;
    return p1.id > p2.id;
}
int main()
{
    pp p[102];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].name >> p[i].y >> p[i].m >> p[i].d;
        p[i].id = i;
    }
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << p[i].name << endl;
    }
    return 0;
}