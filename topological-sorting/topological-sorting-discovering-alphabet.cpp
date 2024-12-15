/*
   Problem Description:
   You discover ancient texts written in an unknown language, potentially organized
   as a dictionary in lexicographical order according to the alphabet of the ancient
   civilization. Your goal is to determine the order of characters in their alphabet
   based on the given dictionary of words.

   Input:
   - An integer n, the number of words.
   - n words sorted lexicographically according to the unknown alphabet.

   Output:
   - The characters of the ancient alphabet in their lexicographical order, separated by spaces.

   Constraints:
   - Words consist of lowercase English letters only.
   - The input dictionary is valid and adheres to the lexicographical rules of the ancient alphabet.

   Example:
   Input:
   5
   tqq
   qtiu
   qtiq
   iqt
   iqu

   Output:
   t u q i
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<char, std::unordered_set<char>> graphFromEdges(const std::vector<std::vector<char>>& edges)
{
    std::unordered_map<char, std::unordered_set<char>> graph;
	for (const auto& edge : edges)
	{
        for (char i : edge)
        {
            if (graph.find(i) == graph.end())
            {
                graph[i] = {};
            }
        }
	}

    for (const auto& edge : edges)
    {
        graph[edge[0]].insert(edge[1]);
    }

    return graph;
}

void topologicalSortingUtil(const std::unordered_map<char, std::unordered_set<char>>& graph,
    char v,
    std::unordered_map<char, bool>& visited,
    std::stack<char>& s)
{
    visited[v] = true;

    for (char adj : graph.at(v))
    {
	    if (!visited[adj])
	    {
            topologicalSortingUtil(graph, adj, visited, s);
	    }
    }

    s.push(v);
}

void topologicalSorting(const std::unordered_map<char, std::unordered_set<char>>& graph)
{
    std::unordered_map<char, bool> visited;
    for (const auto& kvp : graph)
    {
        visited[kvp.first] = false;
    }

    std::stack<char> s;

    for (const auto& kvp : graph)
    {
        if (!visited[kvp.first])
        {
            topologicalSortingUtil(graph, kvp.first, visited, s);
        }
    }

    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
}

int main()
{
    int wordsCount;
    std::cin >> wordsCount;
    std::vector<std::string> words(wordsCount, "");
    for (int i = 0; i < wordsCount; i++)
    {
        std::cin >> words[i];
    }

    std::vector<std::vector<char>> edges;

    for (int i = 0; i < wordsCount - 1; i++)
    {
        size_t firstWordIndexator = 0, secondWordIndexator = 0;

        while (firstWordIndexator < words[i].size() &&
               secondWordIndexator < words[i + 1].size() &&
            words[i][firstWordIndexator] == words[i + 1][secondWordIndexator])
        {
            firstWordIndexator++;
            secondWordIndexator++;
        }

        if (firstWordIndexator == words[i].size() && words[i].size() == secondWordIndexator)
        {
            continue; //two equal words, cannot infer anything
        }

        if (firstWordIndexator >= words[i].size())
        {
            continue;
        }

        edges.push_back({ words[i][firstWordIndexator], words[i + 1][secondWordIndexator] });
    }

    topologicalSorting(graphFromEdges(edges));
}

