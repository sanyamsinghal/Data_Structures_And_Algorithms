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
vector<ll> tree[N];
ll depth[N] = {0};
vector<ll> ans(N);
void calculate_depths(ll node, ll par)
{
    for (ll child : tree[node])
    {
        if (child != par)
        {
            calculate_depths(child, node);
            depth[node] = max(1 + depth[child], depth[node]);
        }
    }
}

void calculate_partial_ans(ll node, ll par, ll par_partial_ans)
{
    vector<ll> prefix, suffix;
    for (ll child : tree[node])
    {
        if (child == par)
            continue;
        prefix.push_back(depth[child]);
        suffix.push_back(depth[child]);
    }

    for (int i = 1; i < prefix.size(); i++)
        prefix[i] = max(prefix[i], prefix[i - 1]);
    for (int i = suffix.size() - 2; i >= 0; i--)
        suffix[i] = max(suffix[i], suffix[i + 1]);
    int cno = 0;
    for (ll child : tree[node])
    {
        if (child != par)
        {
            ll op1 = (cno == 0) ? INT_MIN : prefix[cno - 1];
            ll op2 = (cno == suffix.size() - 1) ? INT_MIN : suffix[cno + 1];
            ll partial_ans = 1 + max(par_partial_ans, max(op1, op2));
            calculate_partial_ans(child, node, partial_ans);
            cno++;
        }
    }
    ans[node] = max(1 + par_partial_ans, depth[node]);
}

void test_case()
{
    ll n;
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    calculate_depths(1, 0);
    calculate_partial_ans(1, -1, -1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}

int main()
{
    fastIO;
    // take_fileIO();
    test_case();
    return 0;
}