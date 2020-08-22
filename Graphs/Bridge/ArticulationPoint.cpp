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
vector<int> articular_points;

void dfs(int node, int par)
{
    vis[node] = true;
    in[node] = low[node] = timer++;
    int children = 0;
    for (int child : graph[node])
    {
        if (child == par)
            continue;
        if (vis[child])
        {
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] >= in[node] && par != -1)
            {
                articular_points.push_back(node);
            }
            children++;
        }
    }
    if (par != -1 && children > 1)
    {
        articular_points.push_back(node);
    }
}

void solve()
{
    timer = 0;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, -1);
    }
}

int main()
{
    fastIO;
    solve();
}