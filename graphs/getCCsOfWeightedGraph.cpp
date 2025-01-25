/*
Това е решението на следната задача от изпита от 2023/2024 по СДА на специалност Софтуерно инженерство към ФМИ, СУ:
https://www.hackerrank.com/contests/2023-2024-2/challenges/components-mst-k/problem.
В общи линии, имаме неориентиран претеглен граф, на който искаме да намерим броя на участващите върхове във всяка компонента на свързаност (КС). 
За всички КС, за които този брой се дели без остатък на дадено число К, търсим сумата на теглата на ребрата на минимално покриващо ги дърво.
Решението на въпросната задача само по себе си не изисква да се възстановяват компонентите на свързаност на графа в цялост, а ни интересува само бройката върхове,
които участват въъ всяка от тях. 
Решението, което предлагам в този файл обаче, възстановява КС на графа и поддържа заявки от типа "връх x и връх y в една и съща КС ли са?", като не използва стандартната
структура Union-Find.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

struct Edge
{
    int from, to, weight;

    bool operator<(const Edge& other) const
    {
        return weight > other.weight;
    }
};

void mergeCC(
    int v1,
    int v2,
    unordered_map<int, shared_ptr<unordered_set<int>>>& cc)
{
    auto cc1 = cc[v1];
    auto cc2 = cc[v2];

    if (cc2->size() > cc1->size())
    {
        std::swap(cc1, cc2);
    }

    for (const auto& x : *cc2)
    {
        cc1->insert(x);
    }

    for (const auto& x : *cc2)
    {
        cc[x] = cc1;
    }
}

int dfs(const unordered_map<int, vector<Edge>>& graph,
    vector<bool>& visited,
    unordered_map<int, shared_ptr<unordered_set<int>>>& cc,
    int start)
{
    visited[start] = true;
    queue<int> q;
    q.push(start);
    int visitedCount = 0;

    while (!q.empty())
    {
        size_t s = q.size();
        for (size_t i = 0; i < s; i++)
        {
            int front = q.front();
            q.pop();
            visitedCount++;

            mergeCC(start, front, cc);

            for (const Edge& e : graph.at(front))
            {
                if (!visited[e.to])
                {
                    visited[e.to] = true;
                    q.push(e.to);
                }
            }
        }
    }

    return visitedCount;
}

long long findSumOfMST(const unordered_map<int, vector<Edge>>& graph, int start)
{
    priority_queue<Edge> pq;
    pq.push({ start, start, 0 });
    unordered_set<int> visited;
    long long sum = 0;

    while (!pq.empty() && visited.size() < graph.size())
    {
        auto top = pq.top();
        pq.pop();

        if (visited.count(top.to))
        {
            continue;
        }

        visited.insert(top.to);
        sum += top.weight;
        for (const auto& adj : graph.at(top.to))
        {
            if (visited.count(adj.to))
            {
                continue;
            }
            pq.push(adj);
        }
    }

    return sum;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int v, e, k;
        cin >> v >> e >> k;

        unordered_map<int, vector<Edge>> graph;
        unordered_map<int, shared_ptr<unordered_set<int>>> cc;
        for (int j = 0; j < v; j++)
        {
            graph[j] = {};
            cc[j] = std::make_shared<std::unordered_set<int>>(unordered_set<int> { j });
        }

        for (int j = 0; j < e; j++)
        {
            int from, to, weight;
            cin >> from >> to >> weight;
            graph[from].push_back(Edge{ from, to, weight });
            graph[to].push_back(Edge{ to, from, weight });
        }

        std::vector<bool> visited(v, false);
        std::vector<int> findMSTOf;
        for (int j = 0; j < v; j++)
        {
            if (!visited[j])
            {
                if (dfs(graph, visited, cc, j) % k == 0)
                {
                    findMSTOf.push_back(j);
                }
            }
        }

        long long answ = 0;
        for (int v : findMSTOf)
        {
            answ += findSumOfMST(graph, v);
        }

        for (const auto& c : cc)
        {
            cout << "vertex=" << c.first << ";connectedComponent = ";
            for (const auto& v : *c.second)
            {
                cout << v << " ";
            }
            cout << "\n";
        }
        cout << (cc[3] == cc[0]) << "\n";

        std::cout << answ << "\n";
    }


    return 0;
}