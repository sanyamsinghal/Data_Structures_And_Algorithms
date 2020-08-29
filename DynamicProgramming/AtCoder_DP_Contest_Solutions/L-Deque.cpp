/*
Just a basic DP problem where at every step you have two choices either to choose
i or j, but after choosing that call the recursion for other player and that value 
should after subtraction should be maximum for both.

It should be maximum for both the cases because if we see X-Y then we maximize it by
taking X such that the remaining is minimum for other person
and minimize X-Y by taking maximum Y such that remaining for another is minimum.

Just think it manually and cache using DP.

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
ll dp[3001][3001][2];


void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

ll bottomUp(vector<ll> &candies, int i, int j, int p) {
  if(i>j){
    return 0;
  }
  else if(dp[i][j][p]!=-1)
    return dp[i][j][p];
  else{
    if(p==1){
      ll op1 = candies[i] - bottomUp(candies, i+1, j, 1-p);
      ll op2 = candies[j] - bottomUp(candies, i, j-1, 1-p);
      return dp[i][j][p] = max(op1, op2);
    }
    else{
      ll op1 = candies[i] - bottomUp(candies, i+1, j, 1-p);
      ll op2 = candies[j] - bottomUp(candies, i, j-1, 1-p);
      return dp[i][j][p] = max(op1, op2);
    }
  }
}

void solve(){
  memset(dp, -1, sizeof(dp));
  ll n; cin>>n;
  vector<ll>candies(n);
  loop(i, 0, n)
    cin>>candies[i];

  cout<<bottomUp(candies, 0, n-1, 1);
}

int main(){
  fastIO;
  take_fileIO();
  
  solve();
  return 0;
}