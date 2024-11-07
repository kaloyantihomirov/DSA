#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> q;
        int i = 0;
        for (; i < students.size(); i++)
        {
            q.push(students[i]);
        }

        std::stack<int> s;
        for (i = 0; i < sandwiches.size(); i++)
        {
            s.push(sandwiches[i]);
        }


        int sendsToBack = 0;
        while (!s.empty() && sendsToBack != s.size())
        {
            if (q.front() == s.top())
            {
                q.pop();
                s.pop();
                sendsToBack = 0;
            }
            else
            {
                int temp = q.front();
                q.pop();
                q.push(temp);
                sendsToBack++;
            }
        }

        return s.size();
    }
};

void testStack()
{
    std::vector<int> test({ 1, 2, 3, 4 });

    std::stack<int> s;
    for (int i = test.size() - 1; i >= 0; i--)
    {
        s.push(test[i]);
    }

    while (!s.empty())
    {
        int temp = s.top();
        std::cout << temp << std::endl;
        s.pop();
    }
}

void testQueue()
{
    std::vector<int> test({1, 2, 3, 4});

    std::queue<int> q;
    for (int i = 0; i < test.size(); i++)
    {
        q.push(test[i]);
    }

    while (!q.empty())
    {
        int temp = q.front();
        std::cout << temp << std::endl;
        q.pop();
    }
}

int main()
{
    //testQueue();
    Solution s;

    std::vector<int> students({1, 1, 1, 0, 0, 1});
    std::vector<int> sandwiches({1, 0, 0, 0, 1, 1});

    std::cout << s.countStudents(students, sandwiches) << std::endl;
}

