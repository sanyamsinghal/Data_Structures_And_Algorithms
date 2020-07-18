/*
    User:- sanyam
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ip(x)                                                                  \
  ll x;                                                                        \
  cin >> x;
#define op(x) cout << x;
#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t)                                                                   \
  int t;                                                                       \
  cin >> t while (t--)
#define triplet pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define fastIO                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n) for (ll i = k; i >= n; i--)
#define init_arr(i, val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()
typedef tree<pll, null_type, less<pll>, rb_tree_tag,
             tree_order_statistics_node_update>

    PBDS;
//pbds.find_by_order(), pbds.order_of_key()

const ll inf = 1e18;
const int N = 100001;

void take_fileIO() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  return;
}

/* ---------------------Code--------------------  */

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  loop(i, 0, n) cin >> a[i];
  loop(i, 0, n) cin >> b[i];

  PBDS pbds;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll curr = b[i] - a[i] + 1;
    ans += pbds.size() - pbds.order_of_key({curr, -1});
    pbds.insert({a[i]-b[i], i});
  }
  cout << ans << endl;
}

int main() {
  fastIO;
  // take_fileIO(); 
  solve();
  return 0;
}