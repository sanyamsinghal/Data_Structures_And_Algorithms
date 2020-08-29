/*
created by Sanyam Singhal
/*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long int
#define mod 1000000007
#define w(t) int t;	cin>>t while(t--)
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

void solve(){
  ll n,w; cin>>n>>w;
  vll weights(n), profits(n);

  loop(i, 0, n){
    cin>>weights[i]>>profits[i];
  }

  ll dp[n+1][w+1];
  memset(dp, 0, sizeof(dp));

  loop(i, 1, n+1){
    loop(j, 1, w+1){
      if(weights[i-1]<=j){
        dp[i][j] = dp[i-1][j-weights[i-1]] + profits[i-1];
      }
      dp[i][j] = max(dp[i][j], dp[i-1][j]);
    }
  }

  cout<<dp[n][w];

  return;
}

int main(){

  fastIO;
  take_fileIO();

  solve();

  return 0;
}