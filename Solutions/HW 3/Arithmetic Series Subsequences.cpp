#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>v;
map<int, int>myMap,prop;
int n, d, m, ans = 0;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n >> d >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        myMap[v[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        int pp = 1;
        if (m == 3)
        {
            ans -= ( myMap[v[i] - d])*prop[v[i] - d];
        }
        pp = 1;
        for (int j = 1; j < m; j++)
        {
            pp *= myMap[v[i] + j * d];
        }
        ans += pp;
        if (pp != 0)
        {
            prop[v[i] + d]++;
        }
        myMap[v[i]]--;
    }
    cout << ans;
}
