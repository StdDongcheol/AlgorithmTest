#include <string>
#include <vector>

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

int n = 5;
int k = 3;

void combi(int Start, std::vector<int> vec, std::vector<int>& vecTarget)
{
    if (vec.size() == k)
    {
        for (int i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << "\n";
        return;
    }

    for (int i = Start + 1; i < n; ++i)
    {
        vec.push_back(vecTarget[i]);
        combi(i, vec, vecTarget);
        vec.pop_back();
    }
}

int main()
{
    std::string strSrc = "블끼얏호우~!";
    
    std::string& strRef = strSrc;
    
    std::string strSrc2 = "돈스탑더뮤직~~!";

    char* c = new char[40];
    
    std::vector<int> vec;
    std::vector<int> vecTarget = { 5, 6, 7, 8, 9 };

    combi(-1, vec, vecTarget);

    return 0;
}