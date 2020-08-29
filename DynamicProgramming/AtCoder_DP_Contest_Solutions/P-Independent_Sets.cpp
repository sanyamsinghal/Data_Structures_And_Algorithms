/*
  Very Nice(for beginners like me ) question of DP on Trees.

  Here we are required to find the possible ways to paint it with given conditions.
  So what we can do is:- 
  take every node and visit its children.
  If that node was painted black then we are bound to color its childs as white, so just recur for every
  child by giving white color and multiply the result for every child branch

  If that node was painted white then we have two choice for every child to be painted, so in addition to above 
  calculation do the calculation by assuming the childs to be white also.
  Then finally add the above two answers.

  So here dp array is dp[total_number_of_nodes][colors_possible]
  then answer is just sum of both possible colors for root node.

  here i have used bool vis array for checking if i am not going from to parent again.
  We here can simply do this by passing a parent variable in recursion

  created by sanyam singhal
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

const ll inf = 1e18;
ll dp[100001][2];
bool vis[100001];

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

ll solve_by_dp(vector<vector<int>> &adj, int node, int parent_color){
  if(dp[node][parent_color]!=-1)
    return dp[node][parent_color];

  vis[node] = true;
  ll ans = 1;
  for(int neigh : adj[node]){
    if(vis[neigh]==false){

      if(parent_color==0){  // 0 here for white
        ll op1 = solve_by_dp(adj, neigh, parent_color)%mod;

        ll op2 = solve_by_dp(adj, neigh,1-parent_color)%mod;
      
        ans = (ans%mod * (op1 + op2)%mod)%mod;

        // cout<<"neigh and node are "<<neigh<<" "<<node<<"color "<<parent_color<<" "<<ans<<endl;
      }
      else{ // 1 for black
        ans = (ans%mod * solve_by_dp(adj, neigh, 1-parent_color)%mod)%mod;
        // cout<<"neigh and node are "<<neigh<<" "<<node<<"color "<<parent_color<<" "<<ans<<endl;
      }
      
    }
  }

  vis[node]=false;
  dp[node][parent_color] = ans;
  return ans;
}

void solve(){
  int n;  
  cin>>n;

  vector<vector<int>>adj(n+1);
  loop(i, 0, n-1){
    int u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(dp, -1, sizeof(dp));
  memset(vis, false, sizeof(vis));

  ll ans = solve_by_dp(adj, 1, 0)%mod;  //by taking root as white
  ll ans2 = solve_by_dp(adj, 1, 1)%mod; //by taking root as black

  ll f_ans = (ans%mod + ans2%mod)%mod;
  cout<<f_ans<<endl;
  return;
}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}