#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void shift(vector<int>& nums)
    {
        int last = nums[0];
        nums[0] = nums[nums.size() - 1];

        for (int i = 1; i < nums.size(); i++)
        {
            int temp = nums[i];
            nums[i] = last;
            last = temp;
        }
    }

    void rotate(vector<int>& nums, int k) 
    {
        for (int i = 0; i < k; i++)
        {
            shift(nums);
        }
    }
};


class SolutionFaster
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int size = nums.size();
        k %= size;

        int count = 0;
        for (int i = 0; count < size; i++)
        {
            int start = i;
            int current = start;
            int lost = nums[current];
            do
            {
                int goTo = (current + k) % size;
                int temp = nums[goTo];
                nums[goTo] = lost;
                lost = temp;
                current = goTo;
                count++;
            } while (current != start);
        }
    }
};

int main()
{
    SolutionFaster sol;
    std::vector<int> nums({1, 2, 3, 4, 5, 6, 7});
    sol.rotate(nums, 3);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }

    std::cout << std::endl;
}
