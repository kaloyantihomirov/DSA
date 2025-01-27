/* Даден ни е ацикличен свързан граф. 
   Искаме да намерих връх v (или няколко такива), за които дървото с корен v има минимална височина.
   Насоки за читателя:
   - Може ли да се напише по-ефективно решение от O(n^2)?
   - Колко такива върха може да има?
   - диаметър на дърво... има ли общо със задачата? 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

void farthestNode(const unordered_map<int, unordered_set<int>>& graph,
                 int curr,
                 int parent,
                 int currHeight,
                 int& maxHeight,
                 int& maxHeightNode)
{
    if(currHeight > maxHeight)
    {
        maxHeight = currHeight;
        maxHeightNode = curr;
    }
    
    for(int adj : graph.at(curr))
    {
        if(adj == parent) continue;
        
        farthestNode(graph, adj, curr, currHeight + 1, maxHeight, maxHeightNode);
    }
}

bool getPathToTargetVertex(const unordered_map<int, unordered_set<int>>& graph,
                          int curr,
                          int target,
                          int parent,
                          vector<int>& path)
{
    if(curr == target)
    {
        path.push_back(curr);
        return true;
    }
    
    for(int adj : graph.at(curr))
    {
        if(adj == parent) continue;
        
        if(getPathToTargetVertex(graph, adj, target, curr, path))
        {
            path.push_back(curr);
            return true;
        }
    }
    
    return false;
}

int main()
{
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int>> graph;
    
    for(int i = 0; i < n; i++)
    {
        graph[i] = {};
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);        
    }
    
    int u = 0;
    int maxHeight = -1;
    int v = -1;
    farthestNode(graph, u, -1, 0, maxHeight, v);
    maxHeight = -1;
    int w = -1;
    farthestNode(graph, v, -1, 0, maxHeight, w);
    vector<int> path;
    getPathToTargetVertex(graph, v, w, -1, path);
    
    size_t pS = path.size();
    if(pS % 2 == 0)
    {
        int mid1 = path[pS / 2 - 1];
        int mid2 = path[pS / 2];
        if(mid1 > mid2)
        {
            std::cout << mid2 << " " << mid1;
        }
        else
        {
            std::cout << mid1 << " " << mid2;
        }
    }
    else
    {
        std::cout << path[pS / 2];
    }
    
     
    return 0;
}
