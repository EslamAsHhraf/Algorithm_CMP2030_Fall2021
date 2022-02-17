#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
	int key;
	Node *left = NULL, *right = NULL;
};
void Set(Node *& root, int val)
{
	if (!root)
	{
		root = new Node;
		root->key = val;
		return;
	}
	if (val > root->key)
		Set(root->right, val);
	else
		Set(root->left, val);
}
int Search(Node *& root, int val, int & flag, int ans = 1)
{
	if (!root)
	{
		ans--;
		flag = 0;
		return ans;
	}
	else if (root->key == val)
	{
		flag = 1;
		return ans;
	}
	if (val > root->key)
		return Search(root->right, val, flag, ans + 1);
	else
		return Search(root->left, val, flag, ans + 1);

}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
	int n, q, a, b, ans = 0, flag = 0;
	cin >> n >> q;
	set<int>mySet;
	Node * parent = NULL;
	vector<Node*> v(1e5 + 5);
	while (n--)
	{
		cin >> a >> b;
		if (mySet.count(a) != 0)
		{
			Set(v[a], b);
		}
		else
		{
			Set(parent, a);
			Set(v[a], b);
			mySet.insert(a);
		}
	}
	while (q--)
	{
		ans = 0;
		cin >> a >> b;
		ans += Search(parent, a, flag);
		if (flag == 0)
		{
			cout << ans << " " << flag << endl;
			continue;
		}
		ans += Search(v[a], b, flag);
		cout << ans << " " << flag << endl;
	}
}
