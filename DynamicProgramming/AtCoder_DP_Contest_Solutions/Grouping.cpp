/*
  Great problem to learn bitmasking techniques and learn DP with Bitmasks.

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
ll a[20][20];
ll visited_all;
ll dp[1<<16];
ll subset_score[1<<16];

void findSums(ll visited_all) {
  for(int subset = visited_all; subset!=0; subset=((subset-1)&visited_all)){
    bitset<17> b(subset);
    subset_score[subset]=0;
    for(int i=0; i<16; i++) {
      if(b[i]==1)
        for(int j=i+1; j<16; j++) 
          if(b[j]==1)
            subset_score[subset] += a[i][j];
    }
  }
  return;
}

ll solve_by_bitmasking_dp(ll curr_mask) {
  if(curr_mask==0){
    return 0;
  }
  else if(dp[curr_mask]!=-1)
    return dp[curr_mask];
  else{
    ll ans = 0;
    for(ll subset_mask = curr_mask; subset_mask!=0; subset_mask=((subset_mask-1)&curr_mask)) {
      ll remaining_rabbits = curr_mask - subset_mask;
      ans = max(ans, subset_score[subset_mask] + solve_by_bitmasking_dp(remaining_rabbits));
    }
    return dp[curr_mask] = ans;
  }
}

void solve() {
  ll n; cin>>n;
  visited_all = ((1<<n)-1);
  
  loop(i, 0, n){
    loop(j, 0, n){
      cin>>a[i][j];
    }
  }
  memset(dp, -1, sizeof dp);

  findSums(visited_all);

  // for(int i=0; i<=((1<<n)-1); i++) {
  //   cout<<subset_score[i]<<endl;
  // }

  cout<<solve_by_bitmasking_dp(visited_all)<<endl;
}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}