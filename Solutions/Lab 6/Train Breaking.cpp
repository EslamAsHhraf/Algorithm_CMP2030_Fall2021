#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector< ll>bar;
//set< ll>mon;
vector< vector<ll>> db;
ll n, m;
int sol(vector<int>&L, int i, int j, vector<vector<int>>&db)
{
    if (db[i][j] != -1)
        return db[i][j];
    if (i == j - 1)
        return 0;
    int Min = INT_MAX;
    for (int z = i + 1; z < j; z++)
    {
        Min = min(Min, sol(L, i, z, db) + sol(L, z, j, db));
    }
    db[i][j] = Min + L[j] - L[i];
    return db[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<int>L(m);
    for (int i = 0; i < m; i++)
        cin >> L[i];
    L.insert(L.begin(), 0);
    L.push_back(n);
    vector<vector<int>>db(m + 2, vector<int>(m + 2, -1));
    cout << sol(L, 0, L.size() - 1, db);
}