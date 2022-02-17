#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool Arithexpr(vector<int> v, vector<bool> b, int val, int idx, bool f) {
	if (idx == 5) {
		if (val == 27)
			return true;
		else
			return false;
	}
	for (int i = 0; i < 5; i++) {
		if (!b[i]) {
			b[i] = true;
			if (Arithexpr(v, b, f ? (val + v[i]) : v[i], idx + 1, 1)
				|| Arithexpr(v, b, f ? (val - v[i]) : v[i], idx + 1, 1)
				|| Arithexpr(v, b, f ? (val * v[i]) : v[i], idx + 1, 1))
				return true;
			b[i] = false;
		}
	}
	return false;
}

int main() {
	vector<int> v(5);
	vector<bool> b(5);
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	if (Arithexpr(v, b, 0, 0, 0))
		cout << "Possible";
	else
		cout << "Impossible";
}
