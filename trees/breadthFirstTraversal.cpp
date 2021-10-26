#include <bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node* left, *right;
};

int height(node *root)
{
	if (root==NULL)
	return 0;
	int h= height(root->left)>height(root->right)?height(root->left):height(root->right);
	return h+1;

}
void printLevelEle(node *root,int Level){
	if (root==NULL)
	return;
	printLevelEle(root->left,Level-1);
	if(Level==1){
		cout<<root->data;
	}
	printLevelEle(root->right,Level-1);
	return;
	
}	
void printLevelOrder(node *root){
	int h=height(root);
	for(int i=1;i<=h;i++){
		printLevelEle(root,i);
	}
}

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Breadth First traversal of binary tree is \n";
    printLevelOrder(root);
 
    return 0;
}
