/*
  Problem link:- https://www.codechef.com/problems/TACHSTCK
  
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

  ll n,d;  cin>>n>>d;
  vector<ll>chopsticks(n);

  for(ll i=0; i<n; i++){
    cin>>chopsticks[i];
  }

  sort(chopsticks.begin(), chopsticks.end());
  ll pairs=0;

  for(ll i=1; i<n; i++){
    if(chopsticks[i] - chopsticks[i-1] <= d){
      pairs++;
      i++;
    }
  }
  
  cout<<pairs<<endl;
  
  return 0;
}