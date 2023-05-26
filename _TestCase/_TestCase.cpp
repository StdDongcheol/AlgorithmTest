#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare(const std::pair<int, std::string>& l, const std::pair<int, std::string>& r)
{
    return l.first < r.first;
}

int main()
{
    int N;
    std::vector<std::pair<int, std::string>> vecN;

    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int Age;
        std::string Name;

        std::cin >> Age >> Name;

        vecN.push_back(std::make_pair(Age, Name));
    }

    std::stable_sort(vecN.begin(), vecN.end(), compare);

    for (auto& i : vecN)
    {
        std::cout << i.first << " " << i.second << "\n";
    }

    return 0;
}