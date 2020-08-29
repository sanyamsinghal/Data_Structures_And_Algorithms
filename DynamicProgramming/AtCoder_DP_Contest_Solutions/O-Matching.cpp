/*

This is a good question to learn DP with bitmasking.

Here when i was unaware of how to use DP with bitmasking what i was doing is
just maintaining a set which will store that what column-index of previous rows 
has been visited and then comparing it with set everytime.

With help of bitmasking we can easily store this thing in a variable with the 
help of bits, and just check if it is visited or not by checking if bit is
set or not.

Space complexity:- O(N * 2^N) because 2^N masks are possible
Time complexity:- O(N * N * 2^N) , the extra N is because we are checking for 
                      every N for every recursive call.

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

int n;  
int mat[22][22];

ll visited_all;
ll dp[22][1LL<<22];

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

ll recursive_solve(int i, int n, ll mask){
  if(visited_all==mask)
    return 1;
  // else if(i==n)
  //   return 0;
  else if(dp[i][mask]!=-1)
    return dp[i][mask];
  else{
    ll ans=0;
    for(int j=0; j<n; j++){
      ll curr_mask = (1<<j);
      if(mat[i][j]==1 &&  ((mask&curr_mask) == 0)){
          ans = (ans + recursive_solve(i+1, n, (mask|curr_mask)))%mod;
      }
    }
    return dp[i][mask]=ans;
  }
}

void solve(){ 
  cin>>n;
  visited_all = (1<<n)-1;
  // cout<<visited_all<<endl;
  loop(i, 0, n)
    loop(j, 0, n)
      cin>>mat[i][j];
  memset(dp, -1, sizeof(dp));
  cout<<recursive_solve(0, n, 0LL)<<endl;
}

int main(){

  fastIO;
  // take_fileIO();
  solve();
  return 0;
}