/*

This question is nice application of Matrix Chain Multiplication.
because here we have to partition the range into two parts like we do in MCM
and after that calculate the answer on those parts which will be furthur used 
to find the answer.

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
const int N = 500;

ll dp[N][N];
ll sumij[N][N];

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

ll solve_by_dp(vector<ll> &a, ll i, ll j){
  if(j==i){ // if the size is 1 then we dont need to combine it with anything
    return 0;
  }
  else if(dp[i][j]!=-1)
    return dp[i][j];
  else{
    ll ans = LLONG_MAX;
    for(ll k=i+1; k<=j; k++){
      ll part1 = solve_by_dp(a, i, k-1);  //solving for range (i, k-1)
      ll part2 = solve_by_dp(a, k, j);    //solving for range (k, j)

      //after we have calculated cost for combining the slimes in separate parts
      //then our answer will be sum of cost for those parts and
      //cost which will be incurred when we combine these two slimes which is nothing but sum of elements in this range.
      ll curr_ans = part1 + part2 + sumij[i][k-1] + sumij[k][j];
      // cout<<curr_ans<<endl;
      if(curr_ans < ans){
        ans = curr_ans;
      }
    }
    return dp[i][j] = ans;
  }
}

void solve(){
  ll n; cin>>n;
  vector<ll>a(n);
  loop(i, 0, n) 
    cin>>a[i];

  memset(dp, -1, sizeof(dp));
  // loop(i, 0, n)
  //   cout<<a[i]<<" ";

  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      if(i==j){
        sumij[i][j] = a[j];
        continue;
      }
      sumij[i][j] = a[j] + sumij[i][j-1];
    }
  }

  // for(int i=0; i<n; i++){
  //   for(int j=0; j<n; j++){
  //     cout<<sumij[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  cout<<solve_by_dp(a, 0, n-1)<<endl;
  return;
}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}