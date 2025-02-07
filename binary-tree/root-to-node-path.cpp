#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  Node(int data, Node *left, Node *right)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};

bool func(Node *root, int node, vector<int> &result)
{
  if (root == NULL)
  {
    return false;
  }

  if (root->data == node || func(root->left, node, result) || func(root->right, node, result))
  {
    result.push_back(root->data);
    return true;
  }

  return false;
}

vector<int> rootNodePath(Node *root, int node)
{
  vector<int> result;

  func(root, node, result);

  reverse(result.begin(), result.end());
  return result;
}

// Main function
int main()
{
  // Creating a sample binary tree
  Node *root = new Node(3);
  root->left = new Node(5);
  root->right = new Node(1);
  root->left->left = new Node(6);
  root->left->right = new Node(2);
  root->right->left = new Node(0);
  root->right->right = new Node(8);
  root->left->right->left = new Node(7);
  root->left->right->right = new Node(4);

  vector<int> result = rootNodePath(root, 7);

  cout << "Root Node Path: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}