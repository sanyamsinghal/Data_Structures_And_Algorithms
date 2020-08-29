/*
  Here we will do it in O(NlogN)
  This solution is for FLowers problem of Atcoder DP contest.

  But same solution is for longest increasing Subsequence(Just assign beauty of all flowers as 1).
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

const ll inf = 1e18;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------From here main coding part starts--------------------  */


ll solve_using_DP_with_Optimizations(vector<pll> &flowers, ll n){
  ll dp[n+1];
  map<ll, ll>meaningful_predecessors;

  dp[1] = flowers[0].second;
  meaningful_predecessors[flowers[0].first] = dp[1];

  ll ans = dp[1];
  // cout<<dp[1]<<endl;
  for(ll i=2; i<=n; i++){
    dp[i]=flowers[i-1].second;
    //we are searching for one whose height just less than current height and
    //the beauty for it will be such that after adding the overall beauty at
    //current index increases.
    auto reqd_previous = meaningful_predecessors.lower_bound(flowers[i-1].first);
    if(reqd_previous!=meaningful_predecessors.begin()) {
      reqd_previous--;
      dp[i] += reqd_previous->second; 
    }

    meaningful_predecessors[flowers[i-1].first] = dp[i];

    //Now removing all the unnecesary ones from map, these are whose height is
    //more than the current one and dp[i]/answer is less.
    auto not_reqd_ones = meaningful_predecessors.upper_bound(flowers[i-1].first);

    while(not_reqd_ones!=meaningful_predecessors.end() && not_reqd_ones->second <= dp[i]) {
      auto temp = not_reqd_ones;
      temp++;
      meaningful_predecessors.erase(not_reqd_ones);
      not_reqd_ones = temp;
    }

    // cout<<dp[i]<<endl;
    ans = max(ans, dp[i]);
    // cout<<dp[i]<<" "<<ans<<endl;
  }

  return ans;
}

void solve(){
  ll n; cin>>n;
  vector<pll> flowers;

  loop(i, 0, n){
    ll height;  cin>>height;
    flowers.push_back(mp(height, 0));
  }
  loop(i, 0, n){
    ll beauty;  cin>>beauty;
    flowers[i] = mp(flowers[i].first, beauty);
  }

  // loop(i, 0, n){
  //   cout<<flowers[i].first<<" "<<flowers[i].second<<", ";
  // }cout<<endl;

  cout<<solve_using_DP_with_Optimizations(flowers, n)<<endl;
  return;
}

int main(){

  fastIO;
  take_fileIO();
  solve();

  return 0;
}