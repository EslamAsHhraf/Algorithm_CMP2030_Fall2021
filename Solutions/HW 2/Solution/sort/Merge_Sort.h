#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& v, int l, int mid, int h)
{
	int n1 = mid - l + 1;
	int n2 = h - mid ;
	vector<int>L(n1 + 1), R(n2 + 1);
	for (int z = 0; z < n1; z++)
	{
		L[z] = v[l + z ];
	}
	for (int z = 0; z < n2; z++)
	{
		R[z] = v[mid + z + 1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0, j = 0;
	for (int k = l; k <= h; k++)
	{
		if (L[i] <= R[j])
		{
			v[k] = L[i];
			i++;
		}
		else
		{
			v[k] = R[j];
			j++;
		}
	}
}
void MergeSort(vector<int>& v, int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (l + h) / 2;
		MergeSort(v, l, mid);
		MergeSort(v, mid + 1, h);
		Merge(v, l, mid, h);
	}
}