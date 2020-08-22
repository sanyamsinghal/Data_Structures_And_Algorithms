/*
  Problem Statement:- spoj.com/problems/DEFKIN/
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

  int t;  cin>>t;
  while(t--){
    ll w,h,n; 
    cin>>w>>h>>n;

    vector<ll>width,heights;
    for(int i=0; i<n; i++){
      ll  data1, data2; cin>>data1>>data2;
      width.push_back(data1);
      heights.push_back(data2);
    }

    width.push_back(0); width.push_back(w+1);
    heights.push_back(0); heights.push_back(h+1);

    sort(width.begin(), width.end());
    sort(heights.begin(), heights.end());

    ll max_w=0, max_h=0;

    for(int i=1; i<width.size(); i++){
      ll consecutive_diff = width[i] - width[i-1]-1;
      max_w = max(max_w, consecutive_diff);
    }

    for(int i=1; i<heights.size(); i++){
      ll consecutive_diff = heights[i] - heights[i-1]-1;
      max_h = max(max_h, consecutive_diff);
    }

    cout<<(max_h*max_w)<<endl;

  }


  return 0;
}
