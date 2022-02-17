#include <bits/stdc++.h>
using namespace std;

int part(vector<int>& v, int low, int high)
{
	int ptr = v[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (v[j] <= ptr)
		{
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[high]);
	return i + 1;
}
//
//void Quick_Sort(vector<int>& v, int low, int high)
//{
//	if (low < high)
//	{
//		int pi = part(v, low, high);
//		Quick_Sort(v, low, pi - 1);
//		Quick_Sort(v, pi + 1, high);
//	}
//}
void Quick_Sort_optimize(vector<int>& v, int L, int H)
{
	if (L < H)
	{
		int ptr = part(v, L, H);
		if ((ptr - L) < (H - ptr))
		{
			Quick_Sort_optimize(v, L, ptr - 1);
			L = ptr + 1;
		}
		else
		{
			Quick_Sort_optimize(v, ptr + 1, H);
			H = ptr - 1;
		}
	}
}