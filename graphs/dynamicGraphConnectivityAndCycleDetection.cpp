/*
Problem: Given a graph with initially N vertices and no edges, edges are added one by one.
After each edge addition, output:
1. The number of connected components in the graph.
2. If the edge created a cycle, append "CYCLE FORMED!" to the output.

Input:
- First line: Integer N (number of vertices).
- Following lines: Pairs of integers u and v (bidirectional edges).

Output:
- For each edge, print the number of connected components. If a cycle is formed, append "CYCLE FORMED!".
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Solution
{
    int n;
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::unordered_map<int,  std::shared_ptr<std::unordered_set<int>>> vertexConnectedComponent;
public:
    Solution(int n) : n(n)
    {
	    for (int i = 1; i <= n; i++)
	    {
            graph[i] = {};
            vertexConnectedComponent[i] = std::make_shared<std::unordered_set<int>>();
            vertexConnectedComponent[i]->insert(i);
	    }
    }

    std::pair<int, bool> addEdge(const std::pair<int, int>& edge)
    {
	    //for every new edge return the number of connected components in the graph
        //and if there is a newly formed cycle

        bool introducesCycle = false;
        if (vertexConnectedComponent[edge.first] == vertexConnectedComponent[edge.second])
        {
            introducesCycle = true;
            return std::make_pair(n, introducesCycle);
        }

        auto component1 = vertexConnectedComponent[edge.first];
        auto component2 = vertexConnectedComponent[edge.second];

        if (component1->size() < component2->size())
        {
            std::swap(component1, component2);
        }

        for (const auto& vertex : *component2)
        {
            component1->insert(vertex);
            vertexConnectedComponent[vertex] = component1;
        }

        graph[edge.first].insert(edge.second);
        graph[edge.second].insert(edge.first);

        return std::make_pair(--n, introducesCycle);
    }
};

int main()
{
    int verticesCount;
    std::cin >> verticesCount;

    Solution s(verticesCount);
    int from, to;

    while (std::cin >> from >> to)
    {
        auto result = s.addEdge(std::make_pair(from, to));

        if (result.second)
        {
            std::cout << result.first << " CYCLE FORMED!\n";
        }
        else
        {
            std::cout << result.first << "\n";
        }
    }

    return 0;
}