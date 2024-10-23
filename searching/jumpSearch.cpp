#include <iostream>

int jumpSearch(int* arr, int size, int target)
{
    if (!arr || !size)
    {
        return -1;
    }

    int jump = sqrt(size);

    int low = 0, high = low + jump;
    while (arr[high] <= target) 
        //неравенството е нестрого, защото:
        //  - представете си, че търсеният елемент е някой arr[high] 
        //  - ако неравенството е строго,
        // при такова положение (arr[high] == target) не бихме
        // въобще влезли в while цикъла, което означава, че текущият интервал
        // за индексите остава [low, high], като търсеният елемент се намира точно на последния индекс, т.е. high, което е изключително неефективно и ще отнеме около jump стъпки за откриването му с for цикъла
        //  - от друга страна, ако направим неравенството нестрого, то в такава
        // ситуация ще влезем в while цикъла, което ще променя low, и то по такъв начин, че когато и да стигнем изпълнението на for цикъла, търсеният елемент ще бъде открит още на първата му итерация
    {
        low = high;
        high = low + jump;

        if (high >= size)
        {
            high = size - 1;
            break;
        }
    }

    for (int i = low; i < high; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[9] = { 1, 12, 23, 23, 34, 45, 54, 76, 999 };

    std::cout << jumpSearch(arr, 9, 54) << std::endl;
}


