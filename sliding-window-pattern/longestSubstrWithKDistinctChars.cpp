// longestSubstrWithKDistinctChars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void deleteLetters(unordered_map<char, int>& m, char l)
{
    if (m[l] == 0)
    {
        m.erase(l);
    }
}

int getLongestSubstrWithDistinctCharacters(string s, int k)
{
    int maxLen = 0;
    int currentLen = 0;
    unordered_map<char, int> m;
    int left = 0;
    for (int right = 0; right < s.size(); right++)
    {
        m[s[right]]++;
        currentLen++;

        if (m.size() <= k)
        {
            maxLen = std::max(maxLen, currentLen);
        }
        else
        {
            while (m.size() > k)
            {
                m[s[left]]--;
                deleteLetters(m, s[left]);
                left++;
                currentLen--;
            }
        }
    }

    return maxLen;
}

int main()
{
    std::cout << getLongestSubstrWithDistinctCharacters("AAIBBBCCC", 3);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
