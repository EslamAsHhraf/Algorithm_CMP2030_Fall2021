#include <bits/stdc++.h>

using namespace std;
#define ll long long

void BossLair(vector<vector<vector<ll >>> &v, int n, int z, int i, int j, ll val, ll &Min) {
    if (i == (n-1) && z == (n-1) && j == (n-1)) {
        if (val < Min)
            Min = val;
        return;
    }
    else if (i == n || z == n || j == n) {
        return;
    }
    if ((j + 1) < n)
        BossLair(v, n, z, i, j + 1, val + v[i][j + 1][z], Min);
    if ((z + 1) < n)
        BossLair(v, n, z + 1, i, j, val + v[i][j][z + 1], Min);
    if ((i + 1) < n)
        BossLair(v, n, z, i + 1, j, val + v[i + 1][j][z], Min);
}

int main() {
    ll n, a, Min = INT_MAX;
    cin >> n;
    vector<vector<vector<ll >>> v(n, vector<vector<ll>>(n, vector<ll>(n)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int z = 0; z < n; z++) {
                cin >> v[i][j][z];
            }

        }
    }
    BossLair(v, n, 0, 0, 0, v[0][0][0], Min);
    cout << Min;
}
