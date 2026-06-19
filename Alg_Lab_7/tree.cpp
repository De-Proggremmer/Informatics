#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
  int value;
  Node *left;
  Node *right;

  Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

int findMax(Node *root) {
  if (root == nullptr) {
    return -1;
  }

  int leftMax = findMax(root->left);
  int rightMax = findMax(root->right);

  return max(root->value, max(leftMax, rightMax));
}

Node *createExampleTree() {
  Node *root = new Node(1);

  root->left = new Node(3);
  root->left->left = new Node(8);
  root->left->right = new Node(10);
  root->left->left->left = new Node(14);
  root->left->left->right = new Node(15);
  root->left->right->right = new Node(3);

  root->right = new Node(5);
  root->right->left = new Node(2);
  root->right->right = new Node(6);
  root->right->right->right = new Node(1);
  root->right->right->left = new Node(0);

  return root;
}

int main() {
  Node *root = createExampleTree();

  int maxVal = findMax(root);
  cout << "Максимальная яркость: " << maxVal << endl;

  return 0;
}
