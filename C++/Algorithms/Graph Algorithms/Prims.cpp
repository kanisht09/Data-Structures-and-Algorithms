/**
  * Given a weighted, undirected graph  with  vertices and  edges. 
  * You want to find a spanning tree of this graph which connects all vertices and 
  * has the least weight (i.e. the sum of weights of edges is minimal). 
  * A spanning tree is a set of edges such that any vertex can reach any other by exactly one simple path. 
  * The spanning tree with the least weight is called a minimum spanning tree.
  */
  
// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

#define V 5

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

int main() {
  int no_edge;  
  int selected[V];

  memset(selected, false, sizeof(selected));

  no_edge = 0;

  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edge < V - 1) {
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) { 
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " -> " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }

  return 0;
}
