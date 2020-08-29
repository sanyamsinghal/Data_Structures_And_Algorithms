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
const int N = 100001;
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

const int MAX = 1000;
ll dp[1000][1000];
ll k;
ll solve(vector<ll> &arr, ll low, ll high)
{
    if (dp[low][high] != -1)
        return dp[low][high];
    else if ((high - low + 1) < 3)
        return high - low + 1;

    else
    {
        ll res = INT_MAX;

        for (int i = low + 1; i <= high - 1; i++)
        {
            for (int j = i + 1; j <= high; j++)
            {
                if (arr[i] == arr[low] + k && arr[j] == arr[low] + 2 * k && solve(arr, low + 1, i - 1) == 0 && solve(arr, i + 1, j - 1) == 0)
                    res = min(res, solve(arr, j + 1, high));
            }
        }

        return dp[low][high] = res;
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    fastIO;
    take_fileIO();

    ll n;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(arr, 0, n - 1);
    return 0;
}