/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define w(t) \
    int t;   \
    cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define loop(i, k, n) for (ll i = k; i <= n; i++)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)

vector<int> graph[100001];
bool vis[100001];
int in[100001];
int low[100001];
int timer = 0;
set<pair<int, int>> bridges;

void dfs(int node, int par)
{
    vis[node] = true;
    in[node] = low[node] = timer;
    timer++;

    for (int child : graph[node])
    {
        if (child == par)
            continue;
        if (vis[child])
        {
            //we are minimizing the current node's time using one of its lowest ancestor
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]); //it is bcoz there may be a chance that child is found some earlier node
            //checking if the current edges is a bridge
            if (in[node] < low[child])
            {
                // cout << node << "->" << child << " edge is a bridge\n";
                bridges.insert({child, node});
            }
        }
    }
}

void solve()
{
    timer = 0;
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int connections;
        cin >> connections;
        while (connections--)
        {
            int v;
            cin >> v;
            graph[i].push_back(v);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, -1);
    }

    cout << bridges.size() << endl;
    for (auto x : bridges)
    {
        cout << x.first << " " << x.second << endl;
    }
}

int main()
{
    fastIO;
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        bridges.clear();

        memset(vis, false, sizeof(vis));
        memset(in, -1, sizeof(in));
        memset(low, -1, sizeof(low));
        solve();
    }

    return 0;
}