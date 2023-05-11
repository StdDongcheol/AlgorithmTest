#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    std::vector<std::pair<int, string>> vecChart;
    std::map<string, int> mapPlayChart;
    std::map<string, std::vector<std::pair<int, int>>> mapSongs;

    for (int i = 0; i < genres.size(); ++i)
    {
        string strGenre = genres[i];
        int iPlayCount = plays[i];

        auto iter = mapPlayChart.find(strGenre);

        if (iter != mapPlayChart.end())
            iter->second += iPlayCount;
        else
            mapPlayChart.insert(make_pair(strGenre, iPlayCount));

        mapSongs[strGenre].push_back(make_pair(iPlayCount, i));
    }

    {
        auto iter = mapPlayChart.begin();
        auto iterEnd = mapPlayChart.end();

        for (; iter != iterEnd; ++iter)
            vecChart.push_back(make_pair(iter->second, iter->first));

        std::sort(vecChart.rbegin(), vecChart.rend());
    }

    auto iter = mapSongs.begin();
    auto iterEnd = mapSongs.end();

    for (; iter != iterEnd; ++iter)
        std::sort(iter->second.rbegin(), iter->second.rend());

    int Count = 0;
    // 높은 재생순위 장르부터 시작
    for (int i = 0; i < vecChart.size(); ++i)
    {
        string strChart = vecChart[i].second;

        if (mapSongs[strChart].size() == 1)
            answer.push_back(mapSongs[strChart][0].second);
        else
        {
            if (mapSongs[strChart][0].first == mapSongs[strChart][1].first)
            {
                if (mapSongs[strChart][0].second > mapSongs[strChart][1].second)
                {
                    answer.push_back(mapSongs[strChart][1].second);
                    answer.push_back(mapSongs[strChart][0].second);
                }
                else
                {
                    answer.push_back(mapSongs[strChart][0].second);
                    answer.push_back(mapSongs[strChart][1].second);
                }
            }

            else
            {
                answer.push_back(mapSongs[strChart][0].second);
                answer.push_back(mapSongs[strChart][1].second);
            }
        }
    }

    return answer;
}