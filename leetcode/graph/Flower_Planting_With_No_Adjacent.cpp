#include <bits/stdc++.h>

using namespace std;

struct node {
  int visited = 0;
  vector<int> adjacent = vector<int> ();
};

struct graph {
  vector<node> nodes;
};
// 1 = 1; 2 = 2; 3 = 4; 4 = 8
void visit(node &currentNode, graph &myGrap) {
  int sum = 0;
  int nodeIndex;
  for (int i = 0; i < currentNode.adjacent.size(); i++) {
    nodeIndex = currentNode.adjacent[i];
    sum += myGrap.nodes[nodeIndex].visited;
  }

  if (!((sum & 1) == 1)) {
    currentNode.visited = 1;
  } else if (!((sum & 2) == 2)) {
    currentNode.visited = 2;
  } else if (!((sum & 4) == 4)) {
    currentNode.visited = 4;
  } else if (!((sum & 8) == 8)) {
    currentNode.visited = 8;
  }
}

void bfs(graph &myGrap, int nodeNum) {
  if (myGrap.nodes[nodeNum].visited == 0) {
    queue<int> queue;
    queue.push(nodeNum);
    int nodeIndex;
    node currentNode;
    int adjNodeIndex;

    while(!queue.empty()) {
      nodeIndex = queue.front();
      queue.pop();
      visit(myGrap.nodes[nodeIndex], myGrap);
      currentNode = myGrap.nodes[nodeIndex]; // make copy

      for (int i = 0; i < currentNode.adjacent.size(); i++) {
        adjNodeIndex = currentNode.adjacent[i];
        if (myGrap.nodes[adjNodeIndex].visited == 0) {
          visit(myGrap.nodes[adjNodeIndex], myGrap);
          queue.push(adjNodeIndex);
        }
      }
    }
  }
}

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
  graph myGraph;
  myGraph.nodes = vector<node> (N+1);
  
  // fullfill graph
  int a;
    int b ;
  for (int i = 0; i < paths.size(); i++) {
    a = paths[i][0];
     b = paths[i][1];

    myGraph.nodes[a].adjacent.push_back(b);
    myGraph.nodes[b].adjacent.push_back(a);
  }
  
  for(int i = 1; i <= N; i++) {bfs(myGraph, i);}

  vector<int> result;
  for (int i = 1; i <= N; i++) {
    // cout << "node: " << i << "cor: " << myGraph.nodes[i].visited << endl;
    if (myGraph.nodes[i].visited == 4) {
      result.push_back(3);
    } else if (myGraph.nodes[i].visited == 8) {
      result.push_back(4);
    } else {
      result.push_back(myGraph.nodes[i].visited);
    }
  }

  return result;
}

int main() {
  vector<vector<int>> x = {{1,2}, {3, 4}}; // [[6,4],[6,1],[3,1],[4,5],[2,1],[5,6],[5,2]]
  vector<int> result = gardenNoAdj(4, x);

  return EXIT_SUCCESS;
}