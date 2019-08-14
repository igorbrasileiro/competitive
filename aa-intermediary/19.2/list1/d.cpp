#include <bits/stdc++.h>
using namespace std;

// D - backets
struct Node {
  int close, open = 0;
};

// void print_node(Node node) {
//   cout << "("<< node.open << ", " << node.matched << ", " << node.close << ")";
// }

// void print_nodes(vector<Node> &sgtree) {
//   for(Node n: sgtree) {
//       print_node(n);
//       cout << " ";
//     }
// }

void func(vector<Node> &sgtree, int node, int left, int right) {
  int minMatch = min(sgtree[left].open, sgtree[right].close);
 
  sgtree[node].open = (sgtree[left].open - minMatch) + sgtree[right].open;
  sgtree[node].close = sgtree[left].close + (sgtree[right].close - minMatch);
}

void build(vector<Node> &sgtree, int node, int l, int r, vector<char> &input) {
  if (l == r) {
    sgtree[node] = Node();
    if (input[l] == '(') {
      sgtree[node].open = 1;
      sgtree[node].close = 0;
    } else {
      sgtree[node].open = 0;
      sgtree[node].close = 1;
    }
  } else {
    int mid = (l + r) / 2;
    int leftChild = 2 * node;
    int rightChild = leftChild + 1;
    build(sgtree, leftChild, l, mid, input);
    build(sgtree, rightChild, mid + 1, r, input);
    sgtree[node] = Node();
    func(sgtree, node, leftChild, rightChild);
  }
}

bool query(vector<Node> &sgtree) {
  return sgtree[1].open == 0 && sgtree[1].close == 0;
}

void update(vector<Node> &sgtree, int node, int l, int r, int pos) {
  if (l == r) {
    if (sgtree[node].open == 1) {
      sgtree[node].open = 0;
      sgtree[node].close = 1;
    } else {
      sgtree[node].open = 1;
      sgtree[node].close = 0;
    }
  } else {
    int mid = (l + r) / 2;
    if (pos <= mid) {
      update(sgtree, 2 * node, l, mid, pos);
    } else {
      update(sgtree, 2 * node + 1, mid + 1, r, pos);
    }

    func(sgtree, node, 2 * node, 2 * node + 1);
  }
}

int main() {
  for (int i = 0; i < 10; i++) {
    printf("Test %d:\n", i+1);
    int word_length;
    scanf("%d\n", &word_length);
    vector<char> input(word_length + 1);

    for (int j = 1; j <= word_length; j++) {
      scanf("%c", &input[j]);
    }

    vector<Node> sgtree (4 * word_length);
    build(sgtree, 1, 1, word_length, input);

    int op, q;
    scanf("%d", &q);
    for (int j = 0; j < q; j++) {
      scanf("%d", &op);
      if (op) {
        update(sgtree, 1, 1, word_length, op);
      } else {
        if(query(sgtree)) {
          printf("YES\n");
        } else {
          printf("NO\n");
        }
      }
    }
  }

  return EXIT_SUCCESS;
}