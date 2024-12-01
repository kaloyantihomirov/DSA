#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Given an array of size n.
 * The problem is to find the max length for a subsequence in the given array,
 * such that all the elements of the subsequence are sorted in increasing order,
 * and also they are alternately odd and even. 
 */

static bool relation(size_t a, size_t b)
{
	return (b > a && (a & 1) != (b & 1));
}

static size_t lisOddEven(const std::vector<size_t>& arr)
{
	std::vector<size_t> dp(arr.size(), 1);

	dp[0] = 1;

	size_t globalMax = 1;
    for (size_t i = 1; i < arr.size(); i++)
    {
		size_t max = 0;
        for (size_t j = 0; j < i; j++)
        {
			if (relation(arr[j], arr[i]))
			{
				max = std::max(max, dp[j]);
			}
        }

		dp[i] = max + 1;
    }

	for (size_t i = 0; i < dp.size(); i++)
	{
		std::cout << dp[i] << " ";
	}
	std::cout << "\n";

	return globalMax;
}

int main()
{
	std::cout << lisOddEven(std::vector<size_t>({5, 6, 9, 4, 7, 8}));
}