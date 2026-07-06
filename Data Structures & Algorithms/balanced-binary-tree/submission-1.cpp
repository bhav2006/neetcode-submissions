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

    int explore(TreeNode* root, bool& flag)
    {
        if(root == NULL || flag == false)
            return 0;

        int left = 1 + explore(root->left,flag);
        int right = 1 + explore(root->right,flag);

        if(flag == true)
            flag = (abs(left - right) <= 1);

        return max(left,right);
    }

    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL)
            return true;

        bool flag = true;
        explore(root,flag);

        return flag;
    }
};
