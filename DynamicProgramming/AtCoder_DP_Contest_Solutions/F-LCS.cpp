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
int dp[3005][3005];

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

string getLCS(string &s, string &t){
  int n = s.size();
  int m = t.size();
  // cout<<len<<endl;
  int i=n, j=m;
  int len = dp[n][m];
  string ans = "";

  while(i>0 && j>0) {
    // cout<<i<<" "<<j;
    if(s[i-1]==t[j-1]) {
      // cout<<"-1\n";
      ans += s[i-1];
      // cout<<s[i-1];
      i--; 
      j--;
      len--;
    }
    else {
      // cout<<"-2\n";
      if(dp[i-1][j] > dp[i][j-1])
        i--;
      else
          j--;
    }
    // cout<<endl;
  }
  // cout<<"remain len = "<<len<<endl;
  reverse(ans.begin(), ans.end());
  return ans;
}

int LCS(string &s, string &t, int n, int m){
  if(n==0 || m==0)
    return dp[n][m] = 0;
  else if(dp[n][m]!=-1)
    return dp[n][m];
  else{
    if(s[n-1]==t[m-1]){
      return dp[n][m] = 1 + LCS(s, t, n-1, m-1);
    }
    else{
      return dp[n][m] = max(LCS(s, t, n-1, m), LCS(s, t, n, m-1));
    }
  }
}

void solve(){
  string s,t;
  cin>>s>>t;
  memset(dp, -1, sizeof(dp));
  int n = s.size();
  int m = t.size();
  int x = LCS(s, t, n, m);

  // for(int i=0; i<=m; i++){
  //   for(int j=0; j<=m; j++){
  //     if(dp[i][j]==-1)
  //       cout<<"0 ";
  //     else
  //       cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  cout<<getLCS(s, t)<<endl;
}

int main(){

  fastIO;
  take_fileIO();

  solve();

  return 0;
}