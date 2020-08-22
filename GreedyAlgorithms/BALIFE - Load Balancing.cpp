  /*
    Problem Link:- https://www.spoj.com/problems/BALIFE/
    Solution by Sanyam Singhal
  */

  #include<bits/stdc++.h>
  using namespace std;
  #define ll long long int

  bool allow=true;

  int main(){
    if(allow){
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    }
    string s;
    while (1){
      ll n; cin>>n;
      if(n==-1) break;
      vector<ll>arr(n);

      for(ll i=0; i<n; i++){
        ll data;  cin>>data;
        if(i==0)  arr[i] = data;
        else  arr[i] = data+arr[i-1];
      }

      ll single_load = arr[n-1]/n;
      if(arr[n-1]%n != 0){
        cout<<"-1\n";
        continue;
      }

      ll ans = LONG_LONG_MIN;
      // cout<<single_load<<endl;
      for(int i=0; i<n; i++){
        ll l = (i+1)*single_load - arr[i];
        ll r = (n-i-1)*single_load - (arr[n-1]-arr[i]);
        // cout<<"i is "<<i<<" -> ";
        // cout<<l<<" "<<r<<endl;
        // cout<<abs(l)<<endl;
        ans = max(ans, abs(l));
      }

      cout<<ans<<endl;
      getline(cin, s);
    }

    return 0;
  }