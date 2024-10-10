#include <iostream>
#include <cstring>

/*
class Solution 
{
public:
    std::string parseString(const std::string& inputStr)
    {
        std::string parsedStr;

        for (int i = 0; i < inputStr.size(); i++)
        {
            if (inputStr[i] != '#')
            {
                parsedStr += inputStr[i];
            }
            else
            {
                if (parsedStr.size() >= 1)
                {
                    parsedStr.erase(parsedStr.size() - 1);
                }
                //if the parsedStr is empty, nothing will happen which is exactly
                //what is supposed to happen according to the problem
            }
        }

        return parsedStr;
    }

    bool backspaceCompare(std::string s, std::string t) 
    {
        std::cout << parseString(s) << std::endl;
        std::cout << parseString(t) << std::endl;

        return parseString(s) == parseString(t);
    }
};
*/
class SolutionLinear
{
public:
    int nextValidCharIdx(std::string s, int index)
    {
        int backspace = 0;
        while (index >= 0)
        {
            if (backspace == 0 && s[index] != '#')
            {
                break;
            }
            else if (s[index] == '#')
            {
                backspace++;
            }
            else
            {
                backspace--;
            }

            index--;
        }

        return index;
    }

    bool backspaceCompare(std::string s, std::string t)
    {
        int p1 = s.size() - 1;
        int p2 = t.size() - 1;

        while (p1 >= 0 || p2 >= 0)
        {
            p1 = nextValidCharIdx(s, p1);
            p2 = nextValidCharIdx(t, p2);

            char c1 = p1 >= 0 ? s[p1] : '\0';
            char c2 = p2 >= 0 ? t[p2] : '\0';

            if (c1 != c2)
            {
                return false;
            }
            p1--;
            p2--;
        }

        return true;
    }
};

int main()
{
    Solution s;
    std::string s1("a#c");
    std::string s2("b");
    std::cout << s.backspaceCompare(s1, s2) << std::endl;
}