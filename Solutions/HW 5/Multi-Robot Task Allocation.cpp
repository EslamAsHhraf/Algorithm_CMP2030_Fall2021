#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
stack<ll>s;
vector<vector<ll>>v;
vector<bool>visit;
set<pair<ll, ll>>mySet;
void dfs_visit(ll i)
{
	visit[i] = true;
	for (int z = 0; z < v[i].size(); z++)
	{
		if (!visit[v[i][z]])
		{
			dfs_visit(v[i][z]);
		}
	}
	s.push(i);
}
void dfs()
{
	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			dfs_visit(i);
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
	cin >> n;
	ll a, b;
	v.resize(n);
	visit.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a != -1)
			v[a].push_back(i);
		if (b != -1)
			v[b].push_back(i);
	}
	dfs();
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
