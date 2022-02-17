#include <bits/stdc++.h>

using namespace std;
void ReadFile(string path,vector<int>&v) 
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

