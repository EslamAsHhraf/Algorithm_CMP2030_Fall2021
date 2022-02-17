#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    ll index;
    ll rating;
    Node* parent; // this is optional
    vector<Node*> children;
};

vector<Node*> nodes;
vector<ll> db;
ll n,a,b;
map<struct Node*, ll> mp;
ll getMaxSumUtil(Node* nod);
ll sumOfGrandChildren(Node* nod)
{
    ll t = 0;
    for (int i = 0; i < nod->children.size(); i++)
    {
        t += getMaxSumUtil(nod->children[i]);
    }
    return t;
}
ll getMaxSumUtil(Node* nod)
{
    if (nod == NULL)
        return 0;
    if (mp.find(nod) != mp.end())
        return mp[nod];

    ll t1 = nod->rating;
    for (int i = 0; i < nod->children.size(); i++)
    {
        t1 += sumOfGrandChildren(nod->children[i]);
    }

    ll t2 = 0;
    for (int i = 0; i < nod->children.size(); i++)
    {
        t2 += getMaxSumUtil(nod->children[i]);
    }

    mp[nod] = max(t1, t2);

    return mp[nod];
}

int main() 
{
    cin >> n;
    nodes.resize(n);
    db.resize(n,-1);
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new Node;
        nodes[i]->index = i;
        cin >> nodes[i]->rating;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        nodes[b]->parent = nodes[a];
        nodes[a]->children.push_back(nodes[b]);
    }
    cout<< getMaxSumUtil(nodes[0]);
    //cout << db[0];
}