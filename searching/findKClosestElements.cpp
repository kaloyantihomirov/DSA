#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	/* по същество това е двоично търсене, което обаче може малко
	   повече от стандартното такова:
	   намира индекса на най-близкото число до целта (target-a), ако 
	   тя не се среща в масива по дефиницията от задача 658. Find K closest
	   elements в Leetcode.
	   */
	int binarySearchTweaked(vector<int>& arr, int t)
	{
		int l = 0;
		int r = arr.size() - 1;

		int candidateInd = -1, candidateDiff = INT32_MAX;
		while (l <= r)
		{
			int m = l + (r - l) / 2;

			int currentDiff = abs(arr[m] - t);
			if (currentDiff < candidateDiff)
			{
				candidateDiff = currentDiff;
				candidateInd = m;
			}
			else if (currentDiff == candidateDiff && arr[m] < arr[candidateInd])
			{
				candidateDiff = currentDiff;
				candidateInd = m;
			}

			if (arr[m] == t)
			{
				return m;
			}
			else if (arr[m] < t)
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}

		return candidateInd;
	}
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x)
	{
		int i = binarySearchTweaked(arr, x);

		vector<int> res;
		res.push_back(arr[i]);

		int p1 = i - 1;
		int p2 = i + 1;

		while (p1 >= 0 && p2 < arr.size() && res.size() < k)
		{
			if (abs(arr[p1] - x) == abs(arr[p2] - x))
			{
				res.push_back(arr[p1--]);
			}
			else if (abs(arr[p1] - x) < abs(arr[p2] - x))
			{
				res.push_back(arr[p1--]);
			}
			else
			{
				res.push_back(arr[p2++]);
			}
		}

		while (p1 >= 0 && res.size() < k)
		{
			res.push_back(arr[p1--]);
		}

		while (p2 < arr.size() && res.size() < k)
		{
			res.push_back(arr[p2++]);
		}

		sort(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution sol;

	std::vector<int> nums = { 1, 2, 3, 4, 5 };

	vector<int> res = sol.findClosestElements(nums, 4, 3);

	for (int i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << " ";
	}

	std::cout << std::endl;
	return 0;
}

