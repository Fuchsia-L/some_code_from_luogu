#include <bits/stdc++.h>
using namespace std;
struct matrix
{
    long long mat[109][109];
    matrix()
    {
        memset(mat, 0, sizeof(mat));
    }
};
long long m = 1E9 + 7;
matrix multiply(matrix a, matrix b, int n)
{
    matrix c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % m;
            }
        }
    }
    return c;
}
matrix qpow(matrix a, long long b, int n)
{
    matrix res;
    for (int i = 1; i <= n; i++)
        res.mat[i][i] = 1;
    while (b)
    {
        if (b & 1)
        {
            res = multiply(res, a, n);
        }
        a = multiply(a, a, n);
        b >>= 1;
    }
    return res;
}
int main()
{
    long long n, k;
    cin >> n >> k;
    matrix a;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a.mat[i][j];
    }
    matrix ans = qpow(a, k, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans.mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}