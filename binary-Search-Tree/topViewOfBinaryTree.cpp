#include <iostream>

#define MAX_NODES 500
#define MAX_DEPTH (MAX_NODES - 1)

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr)
    {}
};

void _topView(Node *root, int droot, int steps, std::pair<int, int> distances[])
{
    if (!root) return;

    if (distances[droot + MAX_DEPTH].first > steps)
    {
        distances[droot + MAX_DEPTH].first = steps;
        distances[droot + MAX_DEPTH].second = root->data;
    }

    _topView(root->left, droot - 1, steps + 1, distances);
    _topView(root->right, droot + 1, steps + 1, distances);
}

void topView(Node *root)
{
    std::pair<int, int> distances[2 * MAX_NODES - 1];
    for (auto &distance: distances)
    {
        distance = {MAX_NODES, -1};
    }
    _topView(root, 0, 0, distances);

    for (const auto &distance: distances)
    {
        if (distance.first != MAX_NODES)
        {
            std::cout << distance.second << " ";
        }
    }
}

// Test Method
void testTopView()
{
    // Construct the tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->left->right->right = new Node(4);
    root->right->right = new Node(8);

    // Call topView
    std::cout << "Top View of the Tree: ";
    topView(root);
    std::cout << std::endl;
}

int main()
{
    testTopView();
    return 0;
}
