#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int value;
    vector<TreeNode*> children;

    TreeNode(int _val = 0, vector<TreeNode*> _children = {}) 
        : value(_val), 
          children(_children) 
        { }
};

class Tree
{
    TreeNode* root;

    TreeNode* findNode(TreeNode* r, int val)
    {
        if (!r) return nullptr;

        if (r->value == val) return r;

        TreeNode* temp = nullptr;
        for (size_t i = 0; i < r->children.size(); i++)
        {
            temp = temp ? temp : findNode(r->children[i], val);
            if (temp) break;
        }

        return temp;
    }

    void _countNodesBelowNode(TreeNode* node, int& count)
    {
        if (!node) return;

        count++;

        for (size_t i = 0; i < node->children.size(); i++)
        {
            _countNodesBelowNode(node->children[i], count);
        }
    }
public:
    Tree() : root(0) { }


    void addNode(int father, int value)
    {
        TreeNode* node = findNode(root, father);
        if (!node) return;
        TreeNode* node2 = findNode(root, value);
        node->children.push_back(node2 ? node2 : new TreeNode(value));
    }

    void addRoot()
    {
        if (!root) root = new TreeNode;
    }

    int countNodesBelowNode(int val)
    {
        TreeNode* node = findNode(root, val);
        if (!node) return 0;
        int count = -1;
        _countNodesBelowNode(node, count);
        return count;

        /*TreeNode* node = findNode(root, val);
        if (!node) return 0;

        int count = node->children.size();
        for (size_t i = 0; i < node->children.size(); i++)
        {
            count += node->children[i]->children.size();
        }
        return count;*/
    }

    void testFunc()
    {
        std::cout << findNode(root, 4)->children.size() << std::endl;
    }
};

int main() {
    int n;
    cin >> n;

    Tree t;
    t.addRoot();
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        t.addNode(x, y);
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << t.countNodesBelowNode(i) << " ";
    }

    std::cout << std::endl;

    //t.testFunc();
}
