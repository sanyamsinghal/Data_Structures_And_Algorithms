/*
  User:- sanyam
*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) int t;	cin>>t while(t--)
#define triplet pair<int,pair<int,int>>
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define loop(i, k, n) for(ll i=k; i<n; i+=1)
#define loop2(i, k, n) for(ll i=k; i>=n; i--)
#define init_arr(i,val) memset(i, val, sizeof(val))
#define sort_cut(x) (x).begin(), (x).end()

const ll inf = 1e18;
const int N =100001;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------Code--------------------  */
ll dp[N][10];

void dfs_leaf(ll i, vector<ll> adj[], ll n) {
  int ch=0;
  for(ll child : adj[i]) {
    dfs_leaf(child, adj, n);
    ch++;
  }
  if(ch!=0){
    adj[i].pb(n);
  }
}

ll dfs(ll i, ll n, ll xor_till, ll xorv_n, vector<ll> adj[]) {
  if(i==n) {
    return xor_till==xorv_n;
  }
  
  for(ll child : adj[i]) {
    // cout<<i<<"->"<<child<<endl;
    ll op1=1, op2=1, op3=1, op4=1;
    op1 = dfs(child, n, xor_till^0, xorv_n, adj);
    op2 = dfs(child, n, xor_till^1, xorv_n, adj);
    op3 = dfs(child, n, xor_till^2, xorv_n, adj);
    op4 = dfs(child, n, xor_till^3, xorv_n, adj);
    dp[i][xor_till] = ((op1%mod * op2%mod)%mod * (op3%mod *op4%mod)%mod)%mod;
  }
  return dp[i][xor_till];
}

void solve() {
  ll n;  cin>>n;
  vector<ll>adj[n+1];
  for(int i=1; i<=n-2; i++) {
    int u, v; cin>>u>>v;
    adj[u].pb(v);
  }
  dfs_leaf(1, adj, n);
  ll ans =((dfs(1, n, 0, 1, adj) + dfs(1, n, 0, 0, adj))%mod + (dfs(1, n, 0, 2, adj) + dfs(1, n, 0, 3, adj))%mod)%mod ;
  cout<<ans<<endl;

  for(int i=1; i<=n; i++) {
    cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
  }

}

int main(){

  fastIO;
  take_fileIO();
  int t;  cin>>t;
  while(t--) {
    solve();
  }
  return 0;
}