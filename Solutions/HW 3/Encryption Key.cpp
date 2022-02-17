#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
vector<pair<int, int>>Hash(1e6 + 5);
int Height(int indx = 1)
{
	if (indx == 0)
		return 0;
	return 1 + max(Height(Hash[indx].first), Height(Hash[indx].second));
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
	int n, sum = 0, a, b, e, h, l, k, Min = INT_MAX, temp, Size;
	char c;
	queue<int>q;
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	cin >> e;
	while (e--)
	{
		cin >> c >> a >> b;
		if (c == 'L')
		{
			Hash[a + 1].first = b + 1;
		}
		else
		{
			Hash[a + 1].second = b + 1;
		}
	}
	h = Height();
	l = v[1] % h;
	q.push(1);
	for (int i = 0; i < l; i++)
	{
		Size = q.size();
		for (int j = 0; j < Size; j++)
		{
			temp = q.front();
			q.pop();
			if (Hash[temp].first != 0)
				q.push(Hash[temp].first);
			if (Hash[temp].second != 0)
				q.push(Hash[temp].second);
		}
	}
	Size = q.size();
	for (int j = 0; j < Size; j++)
	{
		int temp = q.front();
		q.pop();
		Min = min(v[temp], Min);
	}
	k = Min % h;
	k = (k == 0) ? 1 : k;
	q.push(1);
	while (q.size() != 0)
	{
		Size = q.size();
		sum = 0;
		for (int i = 0; i < Size; i++)
		{
			temp = q.front();
			q.pop();
			sum += v[temp];
			if (Hash[temp].first != 0)
				q.push(Hash[temp].first);
			if (Hash[temp].second != 0)
				q.push(Hash[temp].second);
		}
		cout << sum;
		for (int i = 0; i < (k - 1); i++)
		{
			Size = q.size();
			for (int j = 0; j < Size; j++)
			{
				temp = q.front();
				q.pop();
				if (Hash[temp].first != 0)
					q.push(Hash[temp].first);
				if (Hash[temp].second != 0)
					q.push(Hash[temp].second);
			}
		}
	}
}
