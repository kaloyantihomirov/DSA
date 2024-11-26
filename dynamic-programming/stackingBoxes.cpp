/* ( A really cool problem :) )
 * Given n boxes [(L_1, W_1, H_1), (L_2, W_2, H_2), ..., (L_n, W_n, H_n)]
 * where box i has length L_i, width W_i, and height H_i, find the height
 * of the tallest possible stack.
 * Box (L_i, W_i, H_i) can be on top of box (L_j, W_j, H_j) if L_i < L_j,
 * W_i < W_j.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    size_t maxHeight(vector<vector<int>>& cuboids) {
        if (cuboids.empty()) return 0;

        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b)
             {
                 return a[0] < b[0];
             }
        );

        vector<size_t> dp(cuboids.size(), 0);
        dp[0] = cuboids[0][2];
        size_t answer = 0;

        for(size_t i = 1; i < cuboids.size(); i++)
        {
            const vector<int>& currCuboid = cuboids[i];

            size_t maxHeight = 0;
            for(size_t j = 0; j < i; j++)
            {
                const vector<int>& cuboid = cuboids[j];

                if (cuboid[0] < currCuboid[0] &&
                    cuboid[1] < currCuboid[1])
                {
                    if (dp[j] > maxHeight)
                    {
                        maxHeight = dp[j];
                    }
                }
            }
            dp[i] = maxHeight + currCuboid[2];
            if (dp[i] > answer)
            {
                answer = dp[i];
            }
        }

        return answer;
    }
};

void testMaxHeight() {
    // Initialize the test case
    vector<vector<int>> cuboids = {
            {4, 5, 3},
            {2, 3, 2},
            {3, 6, 2},
            {1, 5, 4},
            {2, 4, 1},
            {1, 2, 2}
    };

    // Create a Solution object and call the maxHeight method
    Solution solution;
    size_t result = solution.maxHeight(cuboids);

    // Print the result
    cout << "Maximum height of stacked cuboids: " << result << endl;
}

int main() {
    testMaxHeight();
    return 0;
}


