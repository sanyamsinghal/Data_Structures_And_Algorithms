#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<pair<int,int>>> &adjaceny_list, int u, int v, int wt){
  adjaceny_list[u].push_back({v, wt});
  adjaceny_list[v].push_back({u, wt});
  return;
}

void dijkstra(vector<vector<pair<int,int>>> &adjaceny_list, int src){
  int v = adjaceny_list.size();

  int dist[v];
  for(int i=0; i<v; i++)  dist[i]=INT_MAX-100;
  
  dist[src]=0; //initialize the source node at dist zero
  set<pair<int,int>>s;  //it is for maintaining the vertices which are updated by current vertex and needs to accesed next.
                    
  s.insert({0,0});

  while(!s.empty()){
    pair<int,int>p = *s.begin();
    s.erase(s.begin());
    int curr_vertex = p.second;

    for(pair<int,int>neigh : adjaceny_list[curr_vertex]){
        int curr_neigh = neigh.first;
        int weight_edge = neigh.second;
        if(dist[curr_vertex] + weight_edge < dist[curr_neigh]){
          dist[curr_neigh] = dist[curr_vertex] + weight_edge;
          s.insert({dist[curr_neigh], curr_neigh});
        }
    }
  }

  for(int i=0; i<v; i++){
    cout<<"dist of "<<i<<" from source "<<src<<" is "<<dist[i]<<endl;
  }

}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int v;  cin>>v;
  vector<vector<pair<int,int>>>adjaceny_list(v);

  int number_of_edges;  cin>>number_of_edges;
  for(int i=0; i<number_of_edges; i++){
    int u,v,wt; cin>>u>>v>>wt;
    u--;  v--;
    addEdges(adjaceny_list, u, v, wt);
  }

  dijkstra(adjaceny_list, 0);

  return 1;
}

