#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<string>A(20000), H(24000,"");
vector<double>Insert(40);
vector<bool>Is_delete(24000);
void ReadFile()
{
	string s;
	ifstream infile("words20K.txt");
	for (int i = 0; i < 20000; i++)
	{
		infile >> A[i];
	}
}
int h_dash(string s)
{
	if (s.size() == 1)
		return (39 * int(s[0]));
	else if (s.size() == 2)
		return  (39 * int(s[0]) + 392 * int(s[1]));
	else if (s.size() == 3)
		return (39 * int(s[0]) + 392 * int(s[1]) + 393 * int(s[2]));
	else
		return  (39 * int(s[0]) + 392 * int(s[1]) + 393 * int(s[2]) + 394 * int(s[3]));

}
void put_IN_Hash()
{
	int t = 0,sum=0;
	for (int i = 0; i < A.size(); i++)
	{
		if ((i + 1) % 500 == 0)
		{
			Insert[t] = double(sum) / 500;
			sum = 0;
			t++;
		}
		int temp= h_dash(A[i]);
		temp %= 24000;
		auto Start = high_resolution_clock::now();
		int count = 0;
		while (H[temp] != "")
		{
			temp++;
			temp %= 24000;
			count++;
			if (count == 24000)
			{
				cout << "Hash table over flow";
				return;
			}
		}
		auto end = high_resolution_clock::now();
		auto Durat = duration_cast<microseconds>(end - Start);
		sum += Durat.count();
		H[temp] = A[i];
		Is_delete[temp] = 0;
	}
}
int Serch(string s,int &indx)
{
	int prop = 0;
	indx = h_dash(s);
	indx %= 24000;
	while (H[indx]!="" || Is_delete[indx]==true)
	{
		if (H[indx] == s)
			return prop;
		indx ++;
		prop++;
	}
	return -1;
}
int main()
{
	int Min = INT_MAX, Max = 0, sum_prop = 0;
	ReadFile();
	put_IN_Hash();
	cout << "the average item insertion time for the each 500 inserted words" << endl;
	for(int i=0;i<40;i++)
		cout << Insert[i]<<" ";
	cout << endl;
	for (int i = 14000; i <= 14999; i++)
	{
		int indx;
		int prop = Serch(A[i],indx);
		if (prop != -1)
		{
			sum_prop += prop;
			Min = min(Min, prop);
			Max = max(Max, prop);
			H[indx] = "";
			Is_delete[indx] = true;
		}
	}
	cout << "Read 1000 words from array A, from index 14000 to 14999" << endl;
	cout << "Min: " << Min << "	" << "Max: " << Max << endl <<
		"Average number of probes across the 1000 searches: " << sum_prop / 1000;
}