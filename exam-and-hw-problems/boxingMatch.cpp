/* Тази задача е давана на домашно 2 по СДА 2024/2025 г.
 Линк в HackerRank: https://www.hackerrank.com/contests/sda-24-25-2/challenges/challenge-3669/problem. */

#include <iostream>
#include <vector>
#include <algorithm>

int binarySearchLeftmost(int arr[], int len, int threshold)
{
    int l = 0;
    int r = len - 1;

    int candidateI = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] >= threshold)
        {
            candidateI = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return candidateI;
}

int binarySearchRightmost(int arr[], int len, int threshold)
{
    int l = 0;
    int r = len - 1;

    int candidateI = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] <= threshold)
        {
            candidateI = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return candidateI;
}

int main()
{
    int studentsCount;
    std::cin >> studentsCount;
    int tournamentsCount;
    std::cin >> tournamentsCount;

    std::vector<int> weights(studentsCount, 0);
    for (int i = 0; i < studentsCount; i++)
    {
        std::cin >> weights[i];
    }

    sort(weights.begin(), weights.end());
    for (int i = 0; i < tournamentsCount; i++)
    {
        int minWeight, maxWeight;
        std::cin >> minWeight >> maxWeight;

        int begin = binarySearchLeftmost(weights.data(), studentsCount, minWeight);
        int end = binarySearchRightmost(weights.data(), studentsCount, maxWeight);

        if (begin == -1 || end == -1 || begin > end) 
			// третото условие не е въобще тривиално, но си представете
		    // масив с тегла, в който елементите са "от двете страни" на интервала за теглото,
			// който търсим - тоест имаме и по-малки тегла от minWeight, и по-големи от maxWeight.
			// вижте например масива [10, 15, 20, 106, 140, 160] с 30 <= w_i <= 80 и вижте защо 
			// това условие е необходимо.
        {
            std::cout << 0 << std::endl;
            continue;
        }

        std::cout << end - begin + 1 << std::endl;
    }
}