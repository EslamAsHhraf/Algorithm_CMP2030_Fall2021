#include <bits/stdc++.h>

using namespace std;
#define ll long long

void BossAvgLair(vector<string> &v, vector<string> &a,vector<bool>&b,ll &ans) {
    if (a.size() == v.size())
    {
        ans++;
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (!b[i])
        {
            b[i] = true;
            char t = ' ';
            if(a.size()!=0)
                 t = a[a.size() - 1].back();
            a.push_back(v[i]);
            if (t !=v[i].front() )
                    BossAvgLair(v, a, b, ans);
            a.pop_back();
            b[i] = false;
        }
    }
}

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<string>v(n),a;
    vector<bool>b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    BossAvgLair(v, a, b, ans);
    cout << ans;
}
