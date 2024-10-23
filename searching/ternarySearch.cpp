#include <iostream>

// https://www.youtube.com/watch?v=o3HPRpbGlbI -> тук има доста добро обяснение
// или поне идеята за "групите", на които се разбива масива от m1 и m2, за
// стигането до различните възможни случаи за преместването им ми беше полезно
int ternarySearch(int arr[], int size, int target)
{
    if (!arr || !size)
    {
        return -1;
    }

    int l = 0;
    int r = size - 1;
    while (l <= r)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        if (arr[m1] == target)
        {
            return m1;
        }
        if (arr[m2] == target)
        {
            return m2;
        }

        if (arr[m1] > target)
        {
            r = m1 - 1;
        }
        else if (arr[m2] < target)
        {
            l = m2 + 1;
        }
        else
        {
            l = m1 + 1;
            r = m2 - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[8] = { 10, 20, 30, 40, 50, 60, 70, 80 };

    std::cout << ternarySearch(arr, 8, 80) << std::endl;
}
