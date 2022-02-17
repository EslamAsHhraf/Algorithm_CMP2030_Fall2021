#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[3][1000000 + 5];
ll db [3][1000000 + 5];
ll n;
ll solve()
{
    db[0][n - 1] = arr[0][n - 1];
    db[1][n - 1] = arr[1][n - 1];
    for (int j = (n-2); j >= 0; j--)
    {
        for (int i = 0; i < 2; i++)
        {
            ll t = (i == 0) ? 1 : 0;
            ll Max = 0;
            if (j + 1 <= (n-1))
                db[i][j] = max(db[i][j], db[t][j + 1]);
            if (j + 2 <= (n-1))
                db[i][j] = max(db[i][j], db[t][j + 2]);
            db[i][j] += arr[i][j];
        }
    }
    
    return max(db[0][0], db[1][0]);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<2;i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << solve();
    
}