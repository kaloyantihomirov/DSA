#include <iostream>
#include <vector>

using namespace std;

int smallestSubArr(std::vector<int>& nums, int targetSum)
{
    int smallestArrSize = nums.size();
    int currentSum = 0;
    int currentArrSize = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        currentSum += nums[right];
        currentArrSize++;
        
        while (currentSum >= targetSum)
        {
            if (currentArrSize < smallestArrSize)
            {
                smallestArrSize = currentArrSize;
            }

            //try to shrink the sliding window
            currentSum -= nums[left];
            left++;
            currentArrSize--;
        }
    }

    return smallestArrSize;
}

int main()
{
    std::cout << "Hello World!\n";
}

