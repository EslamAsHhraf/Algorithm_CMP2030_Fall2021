#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll arr[1000 + 5][1000 + 5];
ll db[1000 + 5][1000 + 5];
set<pair<ll, ll>>mySet;
ll solve(ll i, ll j)
{
    if (i == (n - 1) && j == (m - 1))
    {
        if (arr[i][j] == 0)
            db[i][j]= 1;
        else
            db[i][j]= 0;
        return db[i][j];
    }
     if (arr[i][j] == -1)
        {
           return 0;
        }
    if (mySet.count({ i,j }) == 0)
    {
       
            ll t1=0, t2=0;
            if ((i + 1) < n)
                t1 = solve(i + 1, j);
            if ((j + 1) < m)
                t2 = solve(i, j + 1);

            db[i][j] = t1 + t2;
            mySet.insert({ i,j });
    }
    return db[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve(0, 0);
    cout << db[0][0];
}