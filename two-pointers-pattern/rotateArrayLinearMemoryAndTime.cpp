#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}

	std::cout << std::endl;
}

class Solution
{
public:
	void rotateOneCycle(vector<int>& nums, int k, int startIndex, vector<int>& passedIndices)
	{
		int size = nums.size();
		int currentIndex = startIndex;
		int lost = nums[currentIndex];

		do
		{
			int newIndex = (currentIndex + k) % size;
			int temp = nums[newIndex];
			nums[newIndex] = lost;
			lost = temp;
			currentIndex = newIndex;
			passedIndices.push_back(currentIndex);
		} while (currentIndex != startIndex);
	}

	void rotate(vector<int>& nums, int k)
	{
		int size = nums.size();
		k %= size;
		vector<int> passedIndices;

		int startIndex = 0;
		while (passedIndices.size() < size)
		{
			rotateOneCycle(nums, k, startIndex, passedIndices);
			startIndex++;
		}
	}
};

int main()
{
	std::vector<int> nums({ 1, 2, 3, 4, 5, 6 });
	Solution sol;
	sol.rotate(nums, 3);
	printVector(nums);
}
