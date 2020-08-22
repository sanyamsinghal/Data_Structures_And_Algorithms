// /*
// User:- sanyam
// */

// #include<bits/stdc++.h>
// using namespace std;

// #define pb push_back
// #define mp make_pair
// #define ll long long int
// #define mod 1000000007
// #define w(t) int t;	cin>>t while(t--)
// #define triplet pair<int,pair<int,int>>
// #define vi vector<int>
// #define vll vector<ll>
// #define pi pair<int,int>
// #define pll pair<ll,ll>
// #define fastIO ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
// #define loop(i, k, n) for(ll i=k; i<n; i+=1)
// #define loop2(i, k, n) for(ll i=k; i>=n; i--)

// const ll inf = 1e18;

// void take_fileIO(){
//   #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//   #endif
//   return;
// }


// /* ---------------------From here main coding part starts--------------------  */
// bool comp(pi a, pi b){
//   if(a.first==b.first)
//     return a.second > b.second;
//   return a.first > b.first;
// }

// void solve(){
//   int n;  cin>>n;
//   vector<pair<int,int>>v;

//   for(int i=1; i<=n; i++){
//     int id, deadline, profit;
//     cin>>id>>deadline>>profit;
//     v.push_back(mp(profit, deadline));
//     // cout<<id<<deadline<<profit<<endl;
//   }
  

//   bool vis[505] = {false};
//   sort(v.begin(), v.end(), comp);

//   // for(int i=0; i<n; i++){
//   //   cout<<v[i].first<<" "<<v[i].second<<endl;
//   // }
//   // cout<<"---\n";

//   int total_profit = 0;
//   int cnt=0;
//   for(int i=0; i<n; i++){
//     int dead = v[i].second;
//     while(dead>0){
//       if(vis[dead]==false && dead<=n){
//         total_profit += v[i].first;
//         vis[dead]=true;
//         cnt++;
//         break;
//         // cout<<dead<<" "<<v[i].first<<endl;
//       }
//       dead--;
//     }
    
//   }

//   cout<<cnt<<" "<<total_profit<<endl;
// }

// int main(){

//   fastIO;
//   take_fileIO();

//   int t; cin>>t;
//   while(t--){
//     solve();
//   }

//   return 0;
// }




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


/* ---------------------From here main coding part starts--------------------  */
bool comp(pi a, pi b){
  if(a.first==b.first)
    return a.second > b.second;
  return a.first > b.first;
}

void solve(){
  int n;  cin>>n;
  vector<pair<int,int>>v;

  for(int i=1; i<=n; i++){
    int id, deadline, profit;
    cin>>id>>deadline>>profit;
    v.push_back(mp(profit, deadline));
    // cout<<id<<deadline<<profit<<endl;
  }
  

  bool vis[500] = {false};
  int available[501];
  for(int i=0; i<=500; i++)
    available[i]=i;
  sort(v.begin(), v.end(), comp);

  // for(int i=0; i<n; i++){
  //   cout<<v[i].first<<" "<<v[i].second<<endl;
  // }
  // cout<<"---\n";

  int total_profit = 0;
  int cnt=0;
  for(int i=0; i<n; i++){
    int dead = v[i].second;
    int available_slot = available[dead];
    if(available_slot > 0){
      if(1){
        total_profit += v[i].first;
        vis[dead]=true;
        available[dead]  =dead-1;
        cnt++;
        break;
      }
    }
  }

  cout<<cnt<<" "<<total_profit<<endl;
}

int main(){

  fastIO;
  take_fileIO();

  int t; cin>>t;
  while(t--){
    solve();
  }

  return 0;
}