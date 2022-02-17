#include <bits/stdc++.h>
using namespace std;

void insetion_Sort(vector<int>& v)
{
	int n = v.size();
	for (int i = 1; i < n; i++)
	{
		int pov = v[i];
		int k = i - 1;
		while (k >= 0 && v[k] > pov)
		{
			v[k + 1] = v[k];
			k--;
		}
		v[k + 1] = pov;
	}
}