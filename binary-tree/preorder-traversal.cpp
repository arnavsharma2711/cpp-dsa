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

void func(Node *root, vector<int> &result)
{
  if (root == NULL)
  {
    return;
  }

  result.push_back(root->data);
  func(root->left, result);
  func(root->right, result);
}

vector<int> preOrder(Node *root)
{
  vector<int> result;

  func(root, result);

  return result;
}

// Main function
int main()
{
  // Creating a sample binary tree
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  // Getting inorder traversal
  vector<int> result = preOrder(root);

  // Displaying the inorder traversal result
  cout << "Preorder Traversal: ";
  // Output each value in the
  // inorder traversal result
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}