// Given the root of a complete binary tree, return the number of the nodes in the tree.

// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree,
// and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at
// the last level h.

// Design an algorithm that runs in less than O(n) time complexity.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    TreeNode *left_ptr = root;
    TreeNode *right_ptr = root;
    int l_height = 0, r_right = 0;
    while (left_ptr)
    {
        left_ptr = left_ptr->left;
        l_height++;
    }
    while (right_ptr)
    {
        right_ptr = right_ptr->right;
        r_right++;
    }
    if (l_height == r_right)
        return pow(2, l_height) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}