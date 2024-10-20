#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) {
            return l[0] < r[0];
        });

        int prevEnd = intervals[0][1], removals = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start < prevEnd)
            {
                removals++;
                prevEnd  = min(end, prevEnd);
            }
            else
            {
                prevEnd = end;
            }
        }

        return removals;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
