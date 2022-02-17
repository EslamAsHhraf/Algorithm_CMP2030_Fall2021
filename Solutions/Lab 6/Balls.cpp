#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector< ll>bar;
pair < ll, pair<ll, ll>> find_min(pair < ll, pair<ll, ll>> p1, pair < ll, pair<ll, ll>> p2)
{
    if (p1.first > p2.first)
        return p2;
    if (p1.first == p2.first&& p1.second.first < p2.second.first)
        return p2;
    else
        return p1;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    ll s, a, b;
    pair < ll, pair<ll, ll>> p;
    pair < ll, pair<ll, ll>> Min = { LLONG_MAX,{0,0} };
    cin >> s >> a >> b;
    ll rem = s / a;
    //sol(s);
    ll Try;
    for(int i=rem;i>=0;i--)
    {
        rem = (s - i * a) % b;
        Try = (s - i * a) / b;
        Min = find_min(Min, { rem,{Try,i} });
    }
    cout << Min.second.second << " " << Min.second.first <<" "<< Min.first;
}