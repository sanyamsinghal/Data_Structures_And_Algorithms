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

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */
ll ans = 0;
vector<ll> tree[N];
ll depth[N] = {0};

void dfs(ll node, ll par)
{
    depth[node] = 1;
    ll mx = 0, mx2 = 0;
    for (ll child : tree[node])
    {
        if (par != child)
        {
            dfs(child, node);
            if (depth[child] > mx)
            {
                mx2 = mx;
                mx = depth[child];
            }
            else
            {
                mx2 = max(mx2, depth[child]);
            }
        }
    }

    depth[node] += mx;
    ans = max(ans, mx + mx2);
}

void solve()
{
    ll n;
    cin >> n;
    ll u, v;
    loop(i, 1, n)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);
    cout << ans << endl;
}

int main()
{
    fastIO;
    // take_fileIO();

    solve();

    return 0;
}