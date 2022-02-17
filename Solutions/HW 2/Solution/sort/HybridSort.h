#include <bits/stdc++.h>
#include "Quick_Sort.h"
#include "Merge_Sort.h"
using namespace std;
void insertion_sort_L_R(vector<int>& v, int start, int end)
{
	for (int j = start; j <= end; j++)
	{
		int key = v[j];
		int i = j - 1;
		while (i >= start && v[i] > key)
		{
			v[i + 1] = v[i];
			i--;
		}
		v[i + 1] = key;
	}
}/*
void selection_sort_L_R(vector<int>& v, int L, int R)
{
	int small;
	for (int i = L; i < R; i++)
	{
		small = i;
		for (int j = i + 1; j <= R; j++)
		{
			if (v[small] > v[j])
				small = j;
		}
		swap(v[small], v[i]);
	}
}*/
void Hybrid_sort(vector<int>& v, int L, int R)
{
	while (L < R)
	{
		if ((R - L + 1) < 20)
		{
			insertion_sort_L_R(v, L, R);
			break;
		}
		else
		{
			int ptr = part(v, L, R);
			if ((ptr - L) < (R - ptr))
			{
				Hybrid_sort(v, L, ptr - 1);
				L = ptr + 1;
			}
			else
			{
				Hybrid_sort(v, ptr + 1, R);
				R = ptr - 1;
			}
		}
	}
}