#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum=0;
map< ll,vector< ll> >mp;
vector< ll >v;
multiset<ll>mySet;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n ;
    ll a, b;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        mp[v[i]].push_back(b);
        sum += b;
    }
    auto ti = mp.end();
    ti--;
    for(int i=ti->first;i>0;i--)
    {
        for (int j= 0; j < mp[i].size(); j++)
        {
            mySet.insert(mp[i][j]);
        }
        if (mySet.size() == 0)
            continue;
        auto del = mySet.end();
        del--;
        sum -= *del;
        mySet.erase(del);
    }
    cout << sum;
}