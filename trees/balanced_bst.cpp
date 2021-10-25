// Code to find whether a Givin binary tree is balanced.
#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node* left;
    node* right;
};
int max(int a,int b){
	return (a>b)?a:b;
}
 int height(node *root)
 {
 if(root==NULL)
 return 0;
return 1+max(height(root->left),height(root->right));
}
bool isBalanced(node *root)
{
	if(root==NULL)
	return true;
	bool l=isBalanced(root->left),r=isBalanced(root->right);
	int hl=height(root->left),hr=height(root->right);
	if(l&&r&&(hl-hr<=1))
	return true;
	return false;
	
}
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}
 
int main()
{
        node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(7);
 
    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}