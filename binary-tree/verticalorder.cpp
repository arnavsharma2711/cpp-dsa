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

void func(Node *root, map<int, vector<int> > &mp, int line)
{
  if (root == NULL)
  {
    return;
  }

  mp[line].push_back(root->data);

  func(root->left, mp, line - 1);
  func(root->right, mp, line + 1);
}

vector<vector<int> > verticalOrder(Node *root)
{
  vector<vector<int> > result;
  map<int, vector<int> > mp;

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
  vector<vector<int> > result = verticalOrder(root);

  // Displaying the inorder traversal result
  cout << "Vertical Order View: " << endl;
  // Output each value in the
  // inorder traversal result
  for (auto level : result)
  {
    for (auto node : level)
    {
      cout << node << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}