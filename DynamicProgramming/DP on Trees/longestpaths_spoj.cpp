/*
  Its like Diameter of n-ary tree

  Problem Statement:- https://www.spoj.com/problems/PT07Z/

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

ll n; 
vector<int>adj[N];
ll ans=0;
ll max_depth_dp[N]={0};

void dfs(ll node, ll par) {
  ll mx1=0, mx2=0;
  for(ll child : adj[node]) {
    if(child!=par) {
      dfs(child, node);
      max_depth_dp[node] = max(max_depth_dp[node], max_depth_dp[child]+1);
      if(max_depth_dp[child]+1 > mx1){
        mx2 = mx1;
        mx1 = max_depth_dp[child]+1;
      }
      else if(max_depth_dp[child]+1 > mx2){
        mx2 = max_depth_dp[child]+1;
      }
    }
  }

  ans = max(ans, mx1+mx2);
}


int main(){
  fastIO;
  take_fileIO();
  
  cin>>n;
  for(int i=1; i<n; i++) {
    ll u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1, 0);
  cout<<ans<<endl;

  // loop(i, 0, n+1){
  //   cout<<max_depth_dp[i]<<endl;
  // }

  return 0;
}