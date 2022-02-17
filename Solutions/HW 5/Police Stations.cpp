#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector< pair<ll, pair<ll, ll>>> edges;
ll n, m, a, x, y, c;
vector< ll> parent;
vector< ll> rnk;

int find(int u)
{
	if (u != parent[u])
		parent[u] = find(parent[u]);
	return parent[u];
}
void merge(int x, int y)
{
	x = find(x), y = find(y);
	if (rnk[x] > rnk[y])
		parent[y] = x;
	else
		parent[x] = y;
	if (rnk[x] == rnk[y])
		rnk[y]++;
}

void kruskalMST()
{
	ll cost = 0, num_police = n;
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (auto it : edges)
	{
		if (it.first >= a)
		{
			break;
		}
		else
		{
			int set_u = find(it.second.first);
			int set_v = find(it.second.second);
			if (set_u != set_v)
			{
				num_police--;
				merge(set_u, set_v);
				cost += it.first;
			}
		}
	}
	cost += num_police * a;
	cout << cost << " " << num_police;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> a;
	edges.resize(m);
	parent.resize(n + 1);
	rnk.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> c;
		edges.push_back({ c, {x, y} });
	}
	kruskalMST();
}