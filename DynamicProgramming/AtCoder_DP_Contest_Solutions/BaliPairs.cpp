/*
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
const int N = 100001;
ll L[N], R[N];
ll dp[N][10];

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

ll solve_by_dp(ll i, ll n, ll sum=0){
  if(i==n){
    return sum%2;
  }
  else if(dp[i][sum]!=-1)
    return dp[i][sum];
  else{
    
    ll op1 = solve_by_dp(i+1, n, (sum + L[i])%2);
    ll op2 = solve_by_dp(i+1, n, (sum + R[i])%2);
    return dp[i][sum] = (op1%mod + op2%mod)%mod;
  }
}

void solve(){
  ll n; cin>>n;
  loop(i, 0, n) cin>>L[i]>>R[i];
  memset(dp, -1, sizeof(dp));

  cout<<solve_by_dp(0, n)<<endl;

}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}