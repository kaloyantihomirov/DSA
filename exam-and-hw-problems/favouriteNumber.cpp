/* Задачата е от второто домашно на курса по СДА 2024-2025 на СИ, ФМИ. 
  Линк в HackerRank: https://www.hackerrank.com/contests/sda-24-25-2/challenges (Problem 01) */

#include <iostream>
#include <vector>
#include <cmath>

int getSweetsByFriendNo(
    long long start, 
    long long end, 
    int prevDepth, 
    long long friendNo)
{
    int currDepth = prevDepth + 1;
    if (end - start + 1 <= 1)
    {
        return currDepth;
    }

    long long m1 = start + (end - start) / 3;
    long long m2 = end - (end - start) / 3;

    if (m1 < friendNo && friendNo < m2)
    {
        return currDepth;
    }
    else if (m1 >= friendNo)
    {
        return getSweetsByFriendNo(start, m1, currDepth, friendNo);
    }
    else
    {
        return getSweetsByFriendNo(m2, end, currDepth, friendNo);
    }
}

int main()
{
    int power;
    std::cin >> power;

    long long lastFrNo = std::pow(3, power);

    int friendsCount;
    std::cin >> friendsCount;

    for (int i = 0; i < friendsCount; i++)
    {
        long long friendNo;
        std::cin >> friendNo;
        std::cout << getSweetsByFriendNo(1, lastFrNo, 0, friendNo) << std::endl;
    }

    return 0;
}
