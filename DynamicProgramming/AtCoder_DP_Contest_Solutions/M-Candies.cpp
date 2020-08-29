/*

Crux :- Multidimensional DP and DP optimizations, Prefix sums

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
ll dp[101][100001];

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

void solve(){
  ll n,k; 
  cin>>n>>k;

  vector<ll>candies(n+1);
  loop(i, 1, 1+n)
    cin>>candies[i];
  memset(dp, 0, sizeof(dp));

  for(int j=0; j<=k; j++){
    dp[1][j] = (candies[1] >= j) ? 1 : 0;
  }

  for(int i=0; i<=n; i++){
    dp[i][0]=1;
  }

  for(int i=2; i<=n; i++){
    for(int j=1; j<=k; j++){
      dp[i][j] = (mod + dp[i][j-1] + dp[i-1][j] - ((j-candies[i]-1)<0 ? 0 : dp[i-1][j-candies[i]-1]))%mod;
    }
  }

  // for(int i=0; i<=n; i++) {
  //   for(int j=0; j<=k; j++) {
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  cout<<dp[n][k]<<endl;
  return;
}

int main(){

  fastIO;
  take_fileIO();

  solve();

  return 0;
}