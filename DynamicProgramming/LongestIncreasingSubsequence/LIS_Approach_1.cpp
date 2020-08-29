/*
  It is a standard Longest Increasing Subsequence Problem Solution
  Recursive Approach
  Time Complexity - O(N^2)
  Space Complexity - O(N^2)

  We can also do it using Bottom Up DP(Iterative one) but i prefer this.

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

int dp[1001][1001];

int LIS_recursive(vector<int> &arr, int i, int n, int prev) {
  if(i>n)
    return 0;
  else if(dp[i][prev]!=-1)
    return dp[i][prev];
  else {
    int op1 = LIS_recursive(arr, i+1, n, prev);
    int op2 = 0;
    if(prev==0 || arr[i-1] > arr[prev-1])
      op2 = 1 + LIS_recursive(arr, i+1, n ,i);
    // else
    //   op2 = 1 + LIS_recursive(arr, i+1, n, i);
    return dp[i][prev] = max(op1, op2);
  }
}

void solve(){
  int n;  cin>>n;
  // base(dp, -1);
  memset(dp, -1, sizeof(dp));
  vector<int>arr(n);
  loop(i, 0, n) 
    cin>>arr[i];

  cout<<LIS_recursive(arr, 1, n, 0)<<endl;

}

int main(){
  fastIO;
  take_fileIO();

  int t;  cin>>t;
  while(t--){
    solve();
  }

  return 0;
}