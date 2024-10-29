#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
private:
    int binarySearch(vector<int>& nums, int l, int r, int target)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return -1;
    }

    int f(vector<int>& nums, int l, int r, int target)
    {
        if (l < 0 || r >= nums.size() || r < l)
        {
            return -1;
        }

        int m = l + (r - l) / 2;

        if (nums[m] <= nums[r])
        {
            if (target >= nums[m] && target <= nums[r])
            {
                return binarySearch(nums, m, r, target);
            }

            r = m - 1;
            return f(nums, l, r, target);
        }
        else
        {
            if (target >= nums[l] && target <= nums[m])
            {
                return binarySearch(nums, l, m, target);
            }

            l = m + 1;
            return f(nums, l, r, target);
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) 
    {
        return f(nums, 0, nums.size() - 1, target);
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {1, 3};

    std::cout << sol.search(nums, 1) << std::endl;
}