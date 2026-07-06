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

class Solution {
public:

    int explore(TreeNode* root, int& diameter)
    {
        if(root == NULL)
            return 0;

        int left = 1 + explore(root->left, diameter);
        int right = 1 + explore(root->right, diameter);

        diameter = max(left+right-2,diameter);

        return max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int diameter = 0;
        explore(root,diameter);

        return diameter;
    }
};
