#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector< ll>bar;
set< ll>mon;
vector< pair<ll, ll> >db(10000 + 5, { -1,-1 });
set<ll >mySet;
ll n, a, m;
pair<ll, ll> sol(ll sum)
{
	if (sum < *mon.begin())
	{
		return { sum,0 };
	}
	if (db[sum].first == -1)
	{
		pair<ll, ll> temp = { INT_MAX,INT_MAX };
		for (auto i : mon)
		{
			if (i <= sum)
			{
				pair<ll, ll> t = sol(sum - i);
				t.second++;
				if (t.first < temp.first)
					temp = t;
				else if ((t.first == temp.first) && (t.second < temp.second))
					temp = t;
			}
		}
		db[sum] = temp;
		mySet.insert(sum);
	}
	return db[sum];
}
void solve()
{
	for (int i = 0; i < n; i++)
	{
		pair<ll, ll> temp = sol(bar[i]);
		cout << temp.first << " " << temp.second << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
	cin >> n;
	bar.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> bar[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		ll a;
		cin >> a;
		if (a != 0)
			mon.insert(a);
	}
	solve();
}