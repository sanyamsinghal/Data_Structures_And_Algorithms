#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// bool comp(pair<string, ll>p1, pair<string, ll>p2){
//   return p1.second<=p2.second;
// }

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;  cin>>t;
  while(t--){
    string blank;
    getline(cin, blank);
    int n;  cin>>n;
    vector<ll>teams;
    ll curr_id=1;
    for(int i=0; i<n; i++){
      string team_name; cin>>team_name;
      int rank; cin>>rank;
      teams.push_back(rank);
    }

    sort(teams.begin(), teams.end());
    ll total_badness=0;
    for(int i=0; i<n; i++){
      if(curr_id!=teams[i]){
        total_badness = total_badness + abs(curr_id - (ll)teams[i]);
        // cout<<teams[i].first<<" ";
      }
      curr_id++;
    }
    cout<<total_badness<<endl;
  }
  return 0;
}