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

void func(Node *root, vector<int> &result, int level)
{
  if (root == NULL)
  {
    return;
  }

  if(level == result.size())
  {
    result.push_back(root->data);
  }
  func(root->left, result, level + 1);
  func(root->right, result, level + 1);
}

vector<int> leftView(Node *root)
{
  vector<int> result;

  func(root, result, 0);

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
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  root->right->right->right = new Node(8);
  root->left->right = new Node(7);

  // Getting inorder traversal
  vector<int> result = leftView(root);

  // Displaying the inorder traversal result
  cout << "Left View: ";
  // Output each value in the
  // inorder traversal result
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}