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

void func(Node *root, vector<vector<int> > &result)
{
  if (root == NULL)
  {
    return;
  }

  result[0].push_back(root->data);
  func(root->left, result);
  result[1].push_back(root->data);
  func(root->right, result);
  result[2].push_back(root->data);
}

vector<vector<int> > preInPostOrder(Node *root)
{
  vector<vector<int> > result(3);

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
  vector<vector<int> > result = preInPostOrder(root);

  // Displaying the inorder traversal result
  cout << "Preorder Traversal: ";
  // Output each value in the
  // inorder traversal result
  for (int val : result[0])
  {
    cout << val << " ";
  }
  cout << endl;

  // Displaying the inorder traversal result
  cout << "Inorder Traversal: ";
  // Output each value in the
  // inorder traversal result
  for (int val : result[1])
  {
    cout << val << " ";
  }
  cout << endl;

  // Displaying the inorder traversal result
  cout << "Postorder Traversal: ";
  // Output each value in the
  // inorder traversal result
  for (int val : result[2])
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}