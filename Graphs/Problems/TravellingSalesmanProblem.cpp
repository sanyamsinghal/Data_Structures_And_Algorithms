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

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
  #endif
  return;
}


/* ---------------------From here main coding part starts--------------------  */

const int N =15;
int visited_all;
int mat[N][N];
int dp[N][(1<<N)];

int tsp(int current_city, int number_of_cities, int mask){
  if(mask==visited_all)
    return mat[current_city][0];
  else if(dp[current_city][mask]!=-1)
    return dp[current_city][mask];
  else{
    int ans = INT_MAX;
    for(int i=0; i<number_of_cities; i++){
      if( (mask & (1<<i)) == 0){
        int curr_cost = mat[current_city][i] + tsp(i, number_of_cities, (mask | (1<<i)));
        ans = min(ans, curr_cost);
      }
    }
    return dp[current_city][mask] = ans; 
  }
}

int main(){

  fastIO;
  take_fileIO();

  int t;  cin>>t;
  while(t--){
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    loop(i, 0, n)
      loop(j, 0, n)
        cin>>mat[i][j];
    visited_all = (1<<n)-1;
    cout<<tsp(0, n, 1)<<endl;
  }

  return 0;
}