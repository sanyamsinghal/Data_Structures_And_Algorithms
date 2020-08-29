/*
  Problem link - https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/ 

  This is a nice problem if you want to learn how LCS type questions work exaclty.

 by sanyam singhal
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

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

ll dp[2001][2001][6];

ll rec(vector<ll> &first_seq, vector<ll> &second_seq, ll n, ll m, ll k){
  if(n==0 || m==0)
    return 0;
  else if(dp[n][m][k]!=-1)
    return dp[n][m][k];
  else{
    ll ans = 0;
    if(first_seq[n]==second_seq[m]){
      ans = 1 + rec(first_seq, second_seq, n-1, m-1, k);
    }
    else{ //without else also
    //no change by using k
      ll op1 = max(rec(first_seq, second_seq, n-1, m, k), rec(first_seq, second_seq, n, m-1, k));
      ll op2=0;
      if(k>0)
        op2 = 1 + rec(first_seq, second_seq, n-1, m-1, k-1);

      ans = max(ans, max(op1, op2));
    }
    return dp[n][m][k] = ans;
  }
}

void solve(){
  ll n,m,k;
  cin>>n>>m>>k;
  vector<ll> first_seq(n+1), second_seq(m+1);

  memset(dp,-1, sizeof(dp));

  for(ll i=1; i<=n; i++)
    cin>>first_seq[i];
  
  for(ll i=1; i<=m; i++)
    cin>>second_seq[i];

  cout<<rec(first_seq, second_seq, n, m, k);

}

int main(){

  fastIO;
  take_fileIO();
  solve();

  return 0;
}