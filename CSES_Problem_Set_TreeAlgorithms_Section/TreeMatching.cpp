/*
  User:- sanyam
*/
#include <bits/stdc++.h>
using namespace std;
#define ip(x) \
    ll x;     \
    cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
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
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
*/
const ll inf = 1e18;
const int N = 2 * 100000 + 1;
void take_fileIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return;
}

/* ---------------------Code--------------------  */

vector<ll> graph[N];
ll dp[N][2];

void dfs(ll node, ll par)
{

    vector<ll> childs;
    for (ll child : graph[node])
    {
        if (child != par)
        {
            dfs(child, node);
            dp[node][0] += max(dp[child][0], dp[child][1]);
            childs.push_back(child);
        }
    }
    ll cn = childs.size();
    if (cn == 0)
        return;
    vector<ll> prefix(cn, 0), suffix(cn, 0);

    for (int i = 0; i < cn; i++)
    {
        prefix[i] += max(dp[childs[i]][0], dp[childs[i]][1]) + ((i != 0) ? prefix[i - 1] : 0);
    }

    for (int i = cn - 1; i >= 0; i--)
    {
        suffix[i] += max(dp[childs[i]][0], dp[childs[i]][1]) + ((i != cn - 1) ? suffix[i + 1] : 0);
    }

    dp[node][0] = suffix[0];
    for (int i = 0; i < cn; i++)
    {
        dp[node][1] = max(dp[node][1],
                          (1 + (i == 0 ? 0 : prefix[i - 1]) + (i == cn - 1 ? 0 : suffix[i + 1]) + dp[childs[i]][0]));
    }
}

void solve()
{
    ll n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    ll ans = max(dp[1][0], dp[1][1]);
    cout << ans << endl;
}

int main()
{
    fastIO;
    // take_fileIO();
    solve();
    return 0;
}