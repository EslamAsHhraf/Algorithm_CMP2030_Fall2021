#include <bits/stdc++.h>

using namespace std;
#define ll long long

void StrDiff(string s, int n, int h) {
    if (s.length() == n) {
        if (count(s.begin(), s.end(), '1') == h)
            cout << s << endl;
        return;
    }
    StrDiff(s + '0', n, h);
    StrDiff(s + '1', n, h);
}

int main() {
    int n, h;
    string s;
    cin >> n>> h;
    StrDiff(s, n, h);
}
