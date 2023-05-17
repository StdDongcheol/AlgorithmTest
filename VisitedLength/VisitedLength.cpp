#include <string>
#include <vector>

using namespace std;
int Count = 0;
bool checkMap[11][11] = {};
#define MAXINDEX 11

void DFS(int _x, int _y, int _depth, std::string& _dirs)
{
    if (_depth >= _dirs.length())
        return;

    if (!checkMap[_y][_x])
    {
        checkMap[_y][_x] = true;
        ++Count;
    }

    switch (_dirs[_depth])
    {
    case 'L':
    {
        if (_x - 1 >= 0)
            _x += -1;
        break;
    }
    case 'R':
    {
        if (_x + 1 < MAXINDEX)
            _x += 1;
        break;
    }
    case 'U':
    {
        if (_y - 1 >= 0)
            _y += -1;
        break;
    }
    case 'D':
    {
        if (_y + 1 < MAXINDEX)
            _y += 1;
        break;
    }
    }

    DFS(_x, _y, _depth + 1, _dirs);

    return;
}

int solution(string dirs)
{
    int answer = 0;

    DFS(5, 5, 0, dirs);

    answer = Count;
    return Count;
}