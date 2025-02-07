#include <iostream>
#include <map>
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

void func(Node *root, map<int, int> &mp, int line)
{
  if (root == NULL)
  {
    return;
  }

  if (mp.find(line) == mp.end())
  {
    mp[line] = root->data;
  }

  func(root->right, mp, line + 1);
  func(root->left, mp, line - 1);
}

vector<int> topView(Node *root)
{
  vector<int> result;
  map<int, int> mp;

  func(root, mp, 0);

  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    result.push_back(it->second);
  }

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
  vector<int> result = topView(root);

  // Displaying the inorder traversal result
  cout << "Top View: ";
  // Output each value in the
  // inorder traversal result
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}