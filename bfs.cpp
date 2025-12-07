//
// Created by Oghenemarho Orukele on 05/12/2025.
//
/*
 * Breath First Search.
 * Used to move through a graph or tree level by level.
 * For a tree, we don't have to worry about repetition.
 * For a graph, we have to take account of nodes we have visited before.
 */

/*
 * Core steps for BFS:
 * 1. A queue for the current layer of exploration
 * 2. A loop to process each node
 * 3. A branching step where nodes are added to the queue.
 *
 * For graph BFS, be sure to evaluate whether the node has been visited in the past.
 */

#include <queue>
#include <vector>

class Node
{
 public:
    int val;
    Node* left;
    Node* right;

    Node(int _val, Node* _left, Node* _right);
};

std::vector<std::vector<int>> levelOrderTraversal(Node* root)
{
    std::vector<std::vector<int>> res;
    std::queue<Node*> queue;
    queue.push(root);

    while (!queue.empty())
    {
        const int n = static_cast<int>(queue.size());
        std::vector<int> newLevel;
        for (int i = 0; i < n; i++)
        {
            const auto node = queue.front();
            newLevel.push_back(node->val);
            for (auto child : {node->left, node->right})
            {
                queue.push(child);
            }
        }
        res.push_back(newLevel);
    }
    return res;
}

int main()
{
    return 0;
}