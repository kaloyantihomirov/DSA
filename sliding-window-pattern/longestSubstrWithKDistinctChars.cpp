/* Find the length of the longest substring with at most k distinct characters. */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

size_t longestSubstringLenWithKDistinctCharacters(const std::string& s, size_t k)
{
    if (s.empty() || k == 0) return 0;

    std::unordered_map<char, size_t> charsCount;
    size_t maxLen = 0;
    size_t currWindowLen = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        charsCount[s[i]]++;
        currWindowLen++;

        if (charsCount.size() <= k)
        {
            maxLen = std::max(maxLen, currWindowLen);
        }
        else
        {
            char charToRemove = s[i - (currWindowLen - 1)];
	        while (charsCount[charToRemove] > 0)
	        {
                charsCount[charToRemove]--;
                currWindowLen--;
	        }
            charsCount.erase(charToRemove);
        }
    }

    return maxLen;
}

int main()
{
    std::cout << longestSubstringLenWithKDistinctCharacters("AAAHHIBC", 2);
}