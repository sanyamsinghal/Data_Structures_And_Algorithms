/*
  Problem link:- https://www.spoj.com/problems/EXPEDI/
  
  This problem concept and intution is worth learning, simiar problem of
  DP - Minimum Jumps to reach end of array, can also be done by this(Easy).

  By Sanyam Singhal
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

  int t;  cin>>t;
  while(t--){
    ll n; cin>>n;
    vector<pair<ll,ll>>petrol_pumps;
    for(ll i=0; i<n; i++){
      ll dist,fuel;
      cin>>dist>>fuel;
      petrol_pumps.push_back(make_pair(dist,fuel));
    }
    sort(petrol_pumps.begin(), petrol_pumps.end());

    ll L,P;
    cin>>L>>P;

    priority_queue<ll>pq;
    ll steps=-1, curr_location=L;
    ll curr_fuel = P;
    ll curr_index_pointer = n-1;
    
    // for(ll i=0; i<n; i++){
    //   cout<<petrol_pumps[i].first<<" "<<petrol_pumps[i].second<<endl;
    // }
    
    while(curr_location>0){
      // cout<<curr_location<<" "<<curr_fuel<<endl;
      if(curr_fuel<=0){
          steps=-1;
          break;
      }
      curr_location -= curr_fuel;
      curr_fuel=0;

      while(curr_index_pointer>=0 && petrol_pumps[curr_index_pointer].first >= curr_location){
        pq.push(petrol_pumps[curr_index_pointer].second);
        curr_index_pointer--;
      }

      if(pq.empty()==false){
        curr_fuel = pq.top();
        pq.pop();
        steps++;
      }
      
    }  

    cout<<steps<<endl;
  }
  return 0;
}