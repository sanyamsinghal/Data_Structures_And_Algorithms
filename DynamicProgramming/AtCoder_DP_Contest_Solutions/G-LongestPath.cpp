  /*
  Nice question of DP on Graphs.
  created by Sanyam Singhal
  /*/

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

  const ll inf = 1e18;

  void take_fileIO(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    return;
  }

  ll dfs(vector<vector<ll>> &adj, vector<ll>&dp, int src){
    if(dp[src]!=-1)
      return dp[src];

    ll ans=1;
    for(int neigh : adj[src]){
      ans = max(ans, dfs(adj, dp, neigh)+1);
    }
    dp[src] = ans;
    return ans;
  }

  void solve(){
    ll n,m; 
    cin>>n>>m;

    vector<vector<ll>>adj(n+1);
    vector<ll> dp(n+1, -1);

    for(int i=0; i<m; i++){
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
    }

    // for(int i=0; i<n; i++)
    //   cout<<dp[i]<<" ";
    // cout<<endl;

    ll ans=0;
    for(int i=0; i<=n; i++){
      ans = max(ans, dfs(adj, dp, i));
    }
    cout<<ans-1<<endl;

    // for(int i=0; i<=n; i++)
    //   cout<<dp[i]<<" ";
    // cout<<endl;

    return;
  }

  int main(){

    fastIO;
    take_fileIO();
    solve();
    return 0;
  }