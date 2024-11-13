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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *prev = nullptr, *curr = root;

        while(curr)
        {
            if (curr->val < key)
            {
                prev = curr;
                curr = curr->right;
            }
            else if (key < curr->val)
            {
                prev = curr;
                curr = curr->right;
            }
            else
            {
                break;
            }
        }

        if (!curr)
        {
            return root;
        }

        if (!curr->left && !curr->right)
        {
            if (curr->val < prev->val)
            {
                prev->left = nullptr;
            }
            else
            {
                prev->right = nullptr;
            }
        }
        else if(!curr->left)
        {
            if (curr->val < prev->val)
            {
                prev->left = curr->right;
            }
            else if (prev->val < curr->val)
            {
                prev->right = curr->right;
            }
        }
        else if (!curr->right)
        {

        }
        else
        {
            
        }

        delete curr;

    }
};