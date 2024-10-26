/* Решението е на следната задача, която се е падала на изпит по СДА на специалност СИ във ФМИ, СУ. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getCookedPancakesByTime(int time, const vector<int>& cookingTimes)
{
    long long pancakes = 0;
    int size = cookingTimes.size();

    for (int i = 0; i < size; i++)
    {
        pancakes += time / cookingTimes[i];
    }

    return pancakes;
}

int main()
{
    long long pancakesCount;
    int chefsCount;

    cin >> pancakesCount >> chefsCount;

    vector<int> cookingTimes(chefsCount, 0);

    for (int i = 0; i < chefsCount; i++)
    {
        cin >> cookingTimes[i];
    }

    int minimumTime = cookingTimes[0];
    for (int i = 1; i < chefsCount; i++)
    {
        if (cookingTimes[i] < minimumTime)
        {
            minimumTime = cookingTimes[i];
        }
    }

    int l = 0;
    long long r = minimumTime * pancakesCount;
    int candidateTime = 0;

    while (l <= r)
    {
        long long m = l + (r - l) / 2;

        long long pancakesByTime = getCookedPancakesByTime(m, cookingTimes);

        // интуицията за модификацията на стандартното двоично търсене, която съм направил,
        // е в общи линии следната:
		// ако условието в първата if проверка е изпълнено, това означава, че до текущото време имаме необходимия брой палачинки,
		// така че записваме текущото време като кандидат за решение в променливата candidateTime, НО и даваме шанс на алгоритъма
		// да се опита да намери по-добро решение с r = m - 1, което интуитивно е ясно, че ще "води" алгоритъма до по-малки стойности
		// на времето (m)
        if (pancakesByTime >= pancakesCount)
        {
            candidateTime = m;
            r = m - 1;
        }
        else 
        {
            l = m + 1;
        }
    }

    std::cout << candidateTime << std::endl;
}
