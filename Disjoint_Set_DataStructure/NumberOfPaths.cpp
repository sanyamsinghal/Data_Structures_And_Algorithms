#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int parent[1000000];
ll size[1000000];
ll total_paths =0;

int find(int x){
  if(parent[x]==x)  return x;
  else return parent[x] = find(parent[x]);
}

void combine(int u, int v){
  int rootU = find(u);
  int rootV = find(v);
  if(rootU==rootV)  return;

  parent[rootU] = rootV;
  total_paths -= (size[rootU]*(size[rootU]-1))/2;
  total_paths -= (size[rootV]*(size[rootV]-1))/2;
  size[rootV] += size[rootU];
  size[rootU]=0;
  total_paths += (size[rootV]*(size[rootV]-1))/2;

  return;
}

int main() {
    int n;  cin>>n;
    map<int, vector<pair<int,int>>>mp;
    for(int i=0; i<n-1; i++){
      int u,v,w;  cin>>u>>v>>w;
      mp[w].push_back({u,v});
    }

    for(int i=1; i<=n; i++){
      parent[i]=i;
      size[i]=1;
    }
    
    int q;  cin>>q;
    vector<pair<int,int>>v;
    for(int i=0; i<q; i++){
      int x;  cin>>x;
      v.push_back({x,i});
    }
    
    sort(v.begin(), v.end());
    vector<int>ans(q);

    for(int i=0; i<q; i++){
      int weight = v[i].first;
      while(it!=mp.end() && (it.first <= weight)){
        
        vector<pair<int,int>>edges = it.second;

        for(int j=0; j<edges.size(); j++){
          int u,v;
          u = edges[j].first, v=edges[j].second;
          combine(u,v);
        }

        it++;
      }

      ans[v[i].second] = total_paths;
    }

    for(int i=0; i<ans.size(); i++){
      cout<<ans[i]<<" ";
    }

    return 0;
}
