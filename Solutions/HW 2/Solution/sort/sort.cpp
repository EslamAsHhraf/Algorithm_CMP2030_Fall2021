#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
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

void Merge(vector<int>& v, int l, int mid, int h)
{
	int n1 = mid - l + 1;
	int n2 = h - mid;
	vector<int>L(n1 + 1), R(n2 + 1);
	for (int z = 0; z < n1; z++)
	{
		L[z] = v[l + z];
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
void Quick_Sort_optimize(vector<int>& v, int L, int H)
{
	while (L < H)
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
}
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

void ReadFile(string path, vector<int>&v)
{
	int a;
	ifstream infile(path);
	while (infile >> a)
	{
		v.push_back(a);
	}
}
void PrintFile(string path, vector<int>&v)
{
	ofstream OutputFile(path);
	for (int i = 0; i < v.size(); i++)
	{
		OutputFile << v[i] << endl;
	}
}

void PrintTime(string path, double time)
{
	ofstream OutputFile(path);
	OutputFile << fixed << setprecision(3) << time / 1000.0 << " milliseconds";
}



int Solve(vector<int> &Data, int Algorithm)
{
	int Time = 0;
	auto Start = high_resolution_clock::now();
	switch (Algorithm)
	{
	case 0:
		Selection_Sort(Data);
		break;
	case 1:
		insetion_Sort(Data);
		break;
	case 2:
		MergeSort(Data, 0, Data.size() - 1);
		break;
	case 3:
		Quick_Sort_optimize(Data, 0, Data.size() - 1);
		break;
	case 4:
		Hybrid_sort(Data, 0, Data.size() - 1);
		break;
	default:
		break;
	}
	auto end = high_resolution_clock::now();
	auto Durat = duration_cast<microseconds>(end - Start);
	return Durat.count();
}
int main(int argc, char* argv[])
{
	int Algorithm = argv[1][0] - '0';
	string Input = argv[2];
	string Output = argv[3];
	string RunTime = argv[4];
	vector<int> Data;

	ReadFile(Input, Data);
	double Time = Solve(Data, Algorithm);
	PrintFile(Output, Data);
	PrintTime(RunTime, Time);
}