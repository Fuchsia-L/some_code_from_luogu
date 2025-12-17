#include <iostream>
using namespace std;
int main()
{
    int sum = 0, maxx = 0, n;
    string maxname;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name;
        char ganbu, xibu;
        int qimo, banji, lunwen, jiang = 0;
        cin >> name >> qimo >> banji >> ganbu >> xibu >> lunwen;
        if (qimo > 80 && lunwen > 0)
            jiang += 8000;
        if (qimo > 85 && banji > 80)
            jiang += 4000;
        if (qimo > 90)
            jiang += 2000;
        if (qimo > 85 && xibu == 'Y')
            jiang += 1000;
        if (banji > 80 && ganbu == 'Y')
            jiang += 850;
        sum += jiang;
        if (maxx < jiang)
        {
            maxx = jiang;
            maxname = name;
        }
    }
    cout << maxname << endl
         << maxx << endl
         << sum << endl;
    return 0;
}