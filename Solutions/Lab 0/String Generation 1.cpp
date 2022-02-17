#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(string s, vector<string>v, vector<char>c, int & count, int n, int k)
{
    if (s.length() == n)
    {
        int num = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (s.find(v[j]) != string::npos)
                num++;
            if (num == k)
            {
                count++;
                break;
            }
        }
        return;
    }
    for (int i = 0; i < c.size(); i++)
    {
        
        solve(s+c[i] , v, c, count, n, k);
    
    }
}
int main() {
    int m, n, k, ans = 0;
    cin >> m >> n >> k;
    string w, e="";
    vector<string>q;
    vector<char>c = { 'A','B','C','D','E' };
    for (int i = 0; i < m; i++)
    {
        cin >> w;
        q.push_back(w);
    }
    solve(e, q, c, ans, n, k);
    cout << ans;
}
