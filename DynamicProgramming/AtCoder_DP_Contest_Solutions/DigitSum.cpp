/*
  Beginner but a good starter question for Digit DP.
  PS:- I also started from this.

  So here the main thing is to derive a recurrence relation for our DP.
  It is quite mathematical thing to do. 

  So, lets suppose string k as from pos1, pos2, ..... ,posN.
  we need to find a number such that (pos1 + pos2 + ... + posN)%D = 0
  
  let pos1 = x, then the task of remaining part is to make a sum such that:-
    (x + s)%D = 0, here s is sum of remaining part.
    on solving we get s = (D - x%D)%D
  
  similarly if we furthur let s%D = d and find the remaining sum, the equation is:-
    (y + s')%D = d
    on solvign we get s' = (D + d - y%D);

  so this dp(pos, d) = summation from x=0 to 9 (dp(pos+1, (D+d-x%D)%D))



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
#define base(i,val) memset(i, val, sizeof(val))
#define all(x) (x).begin(), (x).end()

const ll inf = 1e18;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------Code--------------------  */

ll dp[10001][101][2];
ll solve_by_dp(string &k, int &D, int pos, int d, int tight) {
  if(dp[pos][d][tight] != -1)
    return dp[pos][d][tight];
  int ub = (tight) ? k[pos]-'0' : 9;
  if(pos == k.length()-1) {
      ll ans=0;
      for(int x=0; x<=ub; x++) {
        if(d == x%D)
          ans++;
      }
      return dp[pos][d][tight] = ans%mod;
  }

  else {
    ll ans=0;
    for(int x=0; x<=ub; x++) {
      ans = (ans + solve_by_dp(k, D, pos+1, (D + d - x%D)%D, tight && (x==ub)))%mod;
    }
    return dp[pos][d][tight] = ans%mod;
  }
}

void solve(){
  string k;
  cin>>k;
  int d;
  cin>>d;
  memset(dp, -1, sizeof dp);
  cout<<(solve_by_dp(k, d, 0, 0, 1) - 1) <<endl;  //this is to remove the 0 as one of the possible number from our answer
}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}