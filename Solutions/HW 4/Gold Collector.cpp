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
        db[i][j] = arr[i][j];
        return     arr[i][j];
    }
    if (mySet.count({ i,j }) == 0)
    {
        ll Max2 = LLONG_MIN;
        if ((i + 1) < n)
            Max2 = max(solve(i + 1, j), Max2);
        if ((j + 1) < m)
            Max2 = max(solve(i, j + 1), Max2);
        if ((j + 1) < m && (i + 1) < n)
            Max2 = max(solve(i + 1, j + 1), Max2);

        db[i][j] = Max2 + arr[i][j];
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