/*
  It is  a DP Algorithm for negative weight edges but not negative weighted cycles.

  created by sanyam singhal
*/

#include<bits/stdc++.h>
using namespace std;

void take_fileIO(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  return;
}

class Edge{
public:
  int src, dest, wt;
};

class Graph{
public:
  int v, e;
  Edge *edges;
  Graph(int v, int e){
    this->v = v;
    this->e = e;
    edges = new Edge[e];
  }

  void addEdge(int u, int v, int wt, int count){
    edges[count].src = u;
    edges[count].dest = v;
    edges[count].wt = wt;
  }

  void BellmanFord(int src){
    int dist[v];
    for(int i=0; i<v; i++)
      dist[i] = INT_MAX;
    
    dist[src]=0;

    //Relaxation Part
    for(int i=1; i<=v-1; i++){
      for(int j=0; j<e; j++){
        int src = edges[j].src;
        int dest = edges[j].dest;
        int weight = edges[j].wt;

        if(dist[src]!=INT_MAX && dist[src] + weight < dist[dest]){
          dist[dest] = dist[src] + weight;
        }
      }
    }

    //check for negative weight cycle
    for(int j=0; j<e; j++){
      int src = edges[j].src;
      int dest = edges[j].dest;
      int weight = edges[j].wt;

      if(dist[src]!=INT_MAX && dist[src] + weight < dist[dest]){
        cout<<"negative weight cycle\n";
        return;
      }
    }

    for(int i=0; i<v; i++){
      cout<<i<<"\t----\t"<<dist[i]<<endl;
    }

  }

};

int main(){
  take_fileIO();

  int v,e;
  cin>>v>>e;

  Graph g(v, e);

  for(int i=0;i<e;i++){
    int u, v, wt;
    cin>>u>>v>>wt;
    g.addEdge(u, v, wt, i);
  }

  g.BellmanFord(0);

  return 0;
}