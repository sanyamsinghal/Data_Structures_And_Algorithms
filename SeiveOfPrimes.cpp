  #include <bits/stdc++.h>
  using namespace std;

  typedef long long ll;
  #define mod 100000005

  typedef vector<int> vi;
  typedef vector<ll> vll;
  typedef pair<int, int> pi;
  typedef pair<ll, ll> pll;
  typedef vector<pair<int,int>> vpi;
  typedef vector<pair<ll,ll>> vpll;

  int sieve[mod+1]={0};

  void printseive(){
    for(int i=0; i<mod; i++){
      if(sieve[i]==1)
        cout<<i<<" ";
    }
    return;
  }

  void primeseive(){
      sieve[0] = 0;
      sieve[1]=0;
      sieve[2]=1;

      for(ll i=3; i<mod; i+=2){
          sieve[i]=1;
      }

      //printseive();
      for(ll i=3; i<mod; i+=2){
          if(sieve[i]==1){
              for(ll j=i; (j*i)<mod; j+=1){
                  sieve[i*j]=0;
              }
          }
      }
      //printseive();
  return;
  }


  int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    primeseive();
    //printseive();
    ll n;   
    cin>>n;
      ll cnt=0;
      for(ll i=2; i<mod; i++){
          if(sieve[i]==1){
              cnt++;
          }
          if(cnt==n){
              cout<<i<<endl;
              break;
          }
      }
    
    return 0;
  }
