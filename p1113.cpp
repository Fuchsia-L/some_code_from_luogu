#include <iostream>
using namespace std;
int main()
{
    int n, a[10005] = {0}, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t, f;
        cin >> t >> t;
        while (cin >> f && f)
        {
            a[i] = max(a[i], a[f]);
        }
        a[i] += t;
        // cout << i << "->" << a[i] << endl;
        ans = max(a[i], ans);
    }
    cout << ans;
}

// #include <iostream>
// using namespace std;
// int n, a[10002][10002];
// int book[10002] = {0};
// int findt(int num, int time)
// {
//     if (book[num])
//         return book[num];
//     int maxx = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         if (a[num][i] == -1)
//         {
//             if (maxx == -1)
//                 maxx = findt(i, time + a[num][0]);
//             else
//                 maxx = max(maxx, findt(i, time + a[num][0]));
//         }
//     }
//     book[num] = maxx;
//     return maxx;
// }
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i][0];
//         int x = -1;
//         while (x != 0)
//         {
//             cin >> x;
//             a[i][x] = -1;
//         }
//     }
//     book[1] = a[1][0];
//     cout << findt(n, 0);
//     return 0;
// }

// #include <iostream>
// #include<queue>
// using namespace std;
// struct mapp
// {
//     int num,time;
// };
// queue <mapp> listt;
// int n, a[10002][10002]={0};
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin>>a[i][0];
//         int x=-1;
//         while (x!=0)
//         {
//             cin>>x;
//             a[i][x]=-1;
//         }

//     }
//     mapp m={1,a[1][0]};
//     listt.push(m);
//     while(!listt.empty()){
//         m=listt.front();
//         for(int i=1;i<=n;i++){
//             if(a[m.num][i]!=0){

//             }
//         }
//     }
//     return 0;
// }