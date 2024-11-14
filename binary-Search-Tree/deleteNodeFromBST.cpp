#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right)
    {}
};

class Solution
{
private:
    TreeNode **findMinNode(TreeNode **root)
    {
        while ((*root)->left)
        {
            root = &(*root)->left;
        }

        return root;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode **curr = &root;

        while (*curr)
        {
            if ((*curr)->val < key)
            {
                curr = &(*curr)->right;
            }
            else if (key < (*curr)->val)
            {
                curr = &(*curr)->left;
            }
            else
            {
                break;
            }
        }

        if (!(*curr))
        {
            return root;
        }

        TreeNode *toDelete = *curr;
        if (!(*curr)->left && !(*curr)->right)
        {
            *curr = nullptr;
        }
        else if (!(*curr)->left)
        {
            *curr = (*curr)->right;
        }
        else if (!(*curr)->right)
        {
            *curr = (*curr)->left;
        }
        else
        {
            TreeNode **minNode = findMinNode(&(*curr)->right);

            *curr = *minNode;
            *minNode = (*minNode)->right;

            (*curr)->left = toDelete->left;
            (*curr)->right = toDelete->right;
        }

        TreeNode *newRoot = toDelete == root ? *curr : root;
        delete toDelete;
        return newRoot;
    }
};

int main()
{
    std::cout << "Hello, world!" << std::endl;
    return 0;
}