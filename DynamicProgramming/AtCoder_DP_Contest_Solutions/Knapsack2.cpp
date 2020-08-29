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

void solve(){
  ll n, w;
  cin>>n>>w;

  vector<ll>weights(n+1), values(n+1);

  loop(i, 1, n+1)
    cin>>weights[i]>>values[i];

  ll maxval = n*1000;
  ll dp[n+1][maxval+1];

  for(int val=0; val<=maxval; val++)
    dp[0][val]=inf;
  
  for(int i=1; i<=n; i++)
    dp[i][0] = 0;
    
  int ans =  INT_MIN;
  // dp[0][0]=0;
  for(int i=1; i<=n; i++){
    for(int val=1; val<=maxval; val++){
      if(i==1){
        if(val == values[1])
          dp[1][val] = weights[1];
        else
          dp[1][val] = inf;
      }
      else{
        dp[i][val] = inf;
        if(values[i] <= val){
          dp[i][val] = min(dp[i-1][val], dp[i-1][val-values[i]] + weights[i]);
        }
        else
        {
          dp[i][val] = min(dp[i][val], dp[i-1][val]);
        }
      }
      if(dp[i][val] <= w)
        ans = max(ans, val);
    }
  }

  cout<<ans<<endl;

  // for(int i=0; i<=n; i++){
  //   for(int val=0; val<=maxval; val++){
  //     cout<<dp[i][val]<<" ";
  //   }
  //   cout<<endl;
  // }

  return;
}

int main(){

  fastIO;
  take_fileIO();
  solve();

  return 0;
}