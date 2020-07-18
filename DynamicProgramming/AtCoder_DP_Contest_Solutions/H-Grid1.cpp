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

int main(){

  fastIO;
  take_fileIO();
  
  int n,m;
  cin>>n>>m;

  vector<vector<char>>matrix(n+1, vector<char>(m+1));
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin>>matrix[i][j];
    }
  }
  
  vector<vector<ll>>dp(n+1, vector<ll>(m+1));
  dp[1][1]=1;

  for(int i=2; i<=n; i++){
    if(matrix[i][1]=='.' && dp[i-1][1]==1)
      dp[i][1]=1;
    else
      dp[i][1]=0;
  }
  for(int j=2; j<=m; j++){
    if(matrix[1][j]=='.' && dp[1][j-1]==1)
      dp[1][j]=1;
    else
      dp[1][j]=0;
  }

  for(int i=2; i<=n; i++){
    for(int j=2; j<=m; j++){
      if(matrix[i][j]=='#')
        dp[i][j]=0;
      else
        dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
    }
  }

  // for(int i=1; i<=n; i++){
  //   for(int j=1; j<=m; j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  cout<<dp[n][m]<<endl;

  return 0;
}