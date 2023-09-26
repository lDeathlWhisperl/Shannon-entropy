#include <iostream>
#include <cmath>
#include <algorithm>

double Shennon(std::string str)
{
    double freq[33] =
    {
        0.07998,
        0.01592,
        0.04533,
        0.01687,
        0.02977,
        0.08483,
        0.00013,
        0.0094,
        0.01641,
        0.07367,
        0.01208,
        0.03486,
        0.04343,
        0.03203,
        0.067,
        0.10983,
        0.02804,
        0.04746,
        0.05473,
        0.06318,
        0.02615,
        0.00267,
        0.00966,
        0.00486,
        0.0145,
        0.00718,
        0.00361,
        0.00037,
        0.01898,
        0.01735,
        0.00331,
        0.00639,
        0.02001
    };
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
    
    double entropy = 0;

    for (char ch : str)
    {
        if (ch == ' ') continue;
        int index = ch - 'а';
        if (index > 5) ++index;
        if (ch == 'ё') index = 6;

        entropy += freq[index] * std::log2(freq[index]);
    }

    return -entropy;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << Shennon("Девочка нашла крокодила");
    return 0;
}
