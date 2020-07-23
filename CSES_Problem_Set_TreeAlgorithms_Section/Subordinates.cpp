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

vector<int> graph[N];
ll dp[N] = {0};

void dfs(int node, int par)
{
    dp[node] = 0;
    for (int child : graph[node])
    {
        if (child != par)
        {
            dfs(child, node);
            dp[node] += 1 + dp[child];
        }
    }
}

void solve()
{
    ll n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int num;
        cin >> num;
        graph[num].push_back(i);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
}

int main()
{
    fastIO;
    // take_fileIO();
    solve();
    return 0;
}