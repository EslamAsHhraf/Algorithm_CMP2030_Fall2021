#include <bits/stdc++.h>
using namespace std;
void Selection_Sort(vector<int>& v)
{
	int small;
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		small = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[small] > v[j])
				small = j;
		}
		swap(v[small], v[i]);
	}
}