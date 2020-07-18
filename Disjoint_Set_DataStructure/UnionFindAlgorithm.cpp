/*
  Union find is an algorithm used to find the set or join the subsets for Disjoint Set DataStructure.
*/
#define ll long long int
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class UnionFind{
  public:
    vector<T> parent;
    vector<T> size_of_component;
    T total_connected_components;
    UnionFind(T n){
        parent.resize(n);
        size_of_component.resize(n,1);
        total_connected_components = n;

        //initialize as parent of i is i
        for(T i=0; i<n; i++){
          parent[i] = i;
        }
    }

    //this function is to find the representative/superparent of a element/node.
    T find(T a){
      if(parent[a] == a)  return a;
      else return parent[a] = find(parent[a]);
    }

    void unite(T a, T b){
      T superparent_a = find(a);
      T superparent_b = find(b);

      if(superparent_a != superparent_b){
        parent[superparent_a] = superparent_b;
        total_connected_components--;
        size_of_component[superparent_b] += size_of_component[superparent_a];
        size_of_component[superparent_a] = 0;
      }
      return;
    }

};

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n,m;  cin>>n>>m;

  UnionFind<int>G(n);   // n-number of vertices and m-number of edges.
  for(int i=0; i<m; i++){
    int x,y;  cin>>x>>y;
    G.unite(x, y);
  }

  cout<<G.total_connected_components<<endl;
  
  /* This is the code for finding the number of pairs which are not reachable from eachother  
  ll ans = 0;
  for(T i=0; i<n; i++){
    T superparent_i = G.find(i);
    ans += ( n - G.size_of_component[superparent_i]);
  }

  cout<<(ans/2)<<endl;
  */
  
  return 0;
}