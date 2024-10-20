#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) {
            return l[0] < r[0];
        });

        int currIntervalBeg = intervals[0][0], currIntervalEnd = intervals[0][1];

        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start <= currIntervalEnd)
            {
                currIntervalEnd = max(end, currIntervalEnd);
            }
            else
            {
                res.push_back({currIntervalBeg, currIntervalEnd});
                currIntervalBeg = start;
                currIntervalEnd = end;
            }
        }
        res.push_back({currIntervalBeg, currIntervalEnd});
        return res;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
