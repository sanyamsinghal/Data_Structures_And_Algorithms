  #include<bits/stdc++.h>
  using namespace std;

  #define pb push_back
  #define mp make_pair
  #define ll long long int
  #define mod 1000000007
  #define w(t) int t;	cin>>t while(t--)
  #define vi vector<int>
  #define vll vector<ll>
  #define pi pair<int,int>
  #define pll pair<ll,ll>
  #define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
  #define loop(i, k, n) for(ll i=k; i<n; i+=1)

  void take_fileIO(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    return;
  }

  void solve(){
    ll n; cin>>n;
    vll heights(n);

    loop(i, 0, n)
      cin>>heights[i];

    vll dp(n+1, 0);

    loop(i, 1, n){
      if(i==1){   //because for reaching i=1 there is only one option i.e. from 0 to 1.
        dp[1] = abs(heights[1]-heights[0]);
        continue;
      }
      ll option1 = dp[i-1] + abs(heights[i-1]-heights[i]);  //jump from i to i+1
      ll option2 = dp[i-2] + abs(heights[i]-heights[i-2]);  //jump from i to i+2

      dp[i] = min(option1, option2);
    }
    
    cout<<dp[n-1]<<endl;
    return;
  }

  int main(){

    fastIO;
    take_fileIO();
    
    solve();

    return 0;
  }