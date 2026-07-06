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

    void explore(TreeNode* root, int maximum, int& cnt)
    {
        if(root == NULL)
            return;

        if(root->val >= maximum)
        {
            cnt++;
            maximum = max(maximum, root->val);
        }

        explore(root->left,maximum,cnt);
        explore(root->right,maximum,cnt);
    }

    int goodNodes(TreeNode* root) 
    {
        int cnt = 0;

        explore(root,INT_MIN,cnt);

        return cnt;
    }
};