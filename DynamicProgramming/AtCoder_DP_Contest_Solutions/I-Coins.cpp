/*
  Problem Link:- https://atcoder.jp/contests/dp/tasks/dp_i

  Many people will gonna say that is probablity dp, or some 2d dp or something else.
  But what i believe and understood it exactly, it is Knapsack problem.
  Like knapsack we have 2 choices for every coin either it is Head or Tail.
  But we have to take the cases in which at last the count of head > tail.

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

double dp[3005][3005];

double rec(vector<double> &coins, int i, int head_count, int tail_count, int n){
  if(i==n){
    if(head_count <= tail_count)
      return 0;
    else
      return 1;
  }
  //here our dp state depends upon on only these 2 variables.
  //because the variation of i is fixed, like it is always i+1
  //the thing which will differentiate dp state is head_count and tail_count.
  else if(dp[head_count][i]!=-1)
    return dp[head_count][i];  

  // So here i will just one by one from every index, and we have two options 
  // op1 = consider the current as head and call recursion for remaining
  // op2 = consider the current as tail and call recursion for remaining
  else {
    double op1=1, op2=1;
    
    op1 = coins[i] * rec(coins, i+1, head_count+1, tail_count, n);
    op2 = (1 - coins[i]) * rec(coins, i+1, head_count, tail_count+1, n);
    // cout<<op1<<" "<<op2<<endl;
    return dp[head_count][i] = op1+op2;
  }
}

void solve() {
  int n;  cin>>n;
  vector<double>coins(n+1);
  loop(i, 0, n)
    cin>>coins[i];
  
  for(int i=0; i<=n; i++){
    for(int j=0; j<=n; j++){
      dp[i][j]=-1;
    }
  }

  //just for having precision of 10^-9
  cout<<fixed << setprecision(10)<<rec(coins, 0, 0, 0,  n)<<endl;

  // for(int i=0; i<=n; i++){
  //   for(int j=0; j<=n; j++){
  //     cout<<dp[i][j]<<"\t";
  //   }
  //   cout<<endl;
  // }

}

int main(){

  fastIO;
  take_fileIO();
  solve();
  return 0;
}