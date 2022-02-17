#include <bits/stdc++.h>

using namespace std;
#define ll long long

int solve(string s1, string s2)
{
    if (s1.size() != s2.size())
        return -1;

    int i;
    for (i = 0; i < s1.length(); i++) {
        if (s1 == s2)
            break;
        char t = s2[0];
        s2.erase(0, 1);
        s2 += t;
    }
    if (i < s1.length())
        return i;
    else
        return -1;
}

void StrReArrang(vector<string> &v, vector<bool> &b, int idx, int num, int move, int &Min)
{
    if (num == v.size()) {
        Min = min(Min, move);
        return;
    }
    int temp = 0;
    for (int i = 0; i < v.size(); i++) {
        if (idx == -1)
        {
            fill(b.begin(), b.end(), false);
            b[i] = true;
            StrReArrang(v, b, i, num + 1, move, Min);
        }
        else if (!b[i])
        {
            b[i] = true;

            temp = solve(v[idx], v[i]);
            if (temp == -1)
            {
                Min = -1;
                break;
            }
            StrReArrang(v, b, idx, num + 1, move + temp, Min);
        }
    }

}

int main() {
    int n, Min = INT_MAX;
    cin >> n;
    vector<string> v(n);
    vector<bool> b(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    StrReArrang(v, b, -1, 0, 0, Min);
    //Min = (Min == INT_MAX) ? -1 : Min;
    cout << Min;
}
