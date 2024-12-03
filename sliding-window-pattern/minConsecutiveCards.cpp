#include <iostream>
#include <unordered_map>
#include <vector>

int minConsecutiveCards(const std::vector<size_t>& cards)
{
    size_t currWindowLen = 0;
    size_t minLen = cards.size() + 1;

    std::unordered_map<size_t, size_t> cardsCount;
    for (size_t i = 0; i < cards.size(); i++)
    {
        cardsCount[cards[i]]++;
        currWindowLen++;

        while (cardsCount[cards[i]] > 1)
        {
            minLen = std::min(minLen, currWindowLen);
            size_t firstCardInWindow = cards[i - (currWindowLen - 1)];
            //the idea is that the firstCardInWindow may or may NOT be the same card as cards[i]
            cardsCount[firstCardInWindow]--;
            currWindowLen--;
        }
    }

    return minLen == cards.size() + 1 ? -1 : minLen;
}

int main()
{
    std::cout << minConsecutiveCards(std::vector<size_t> { 3, 4, 2, 3, 4, 7 });
}