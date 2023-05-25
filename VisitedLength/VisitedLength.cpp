#include <iostream>
#include <string>
#include <vector>

using namespace std;
int Count = 0;
bool checkMap[11][11][4] = {};

#define MAXINDEX 11

void DFS(int _x, int _y, int _depth, std::string& _dirs)
{
    while (_depth < _dirs.length())
    {
        bool Check[4] = { false };

        if (_x - 1 >= 0)
            Check[0] = true;

        if (_x + 1 < MAXINDEX)
            Check[1] = true;

        if (_y - 1 >= 0)
            Check[2] = true;

        if (_y + 1 < MAXINDEX)
            Check[3] = true;

        int NextX = _x;
        int NextY = _y;

        switch (_dirs[_depth])
        {
            case 'L':
            {
                if (!Check[0])
                    break;
        
                NextX -= 1;
                if (!checkMap[_y][_x][0] && !checkMap[NextY][NextX][1])
                {
                    ++Count;
                    checkMap[_y][_x][0] = true;
                }
                break;
            }
            case 'R':
            {
                if (!Check[1])
                    break;
        
                NextX += 1;
                if (!checkMap[_y][_x][1] && !checkMap[NextY][NextX][0])
                {
                    ++Count;
                    checkMap[_y][_x][1] = true;
                }
                break;
            }
            case 'U':
            {
                if (!Check[2])
                    break;
        
                NextY -= 1;
                if (!checkMap[_y][_x][2] && !checkMap[NextY][NextX][3])
                {
                    ++Count;
                    checkMap[_y][_x][2] = true;
                }
                break;
            }
            case 'D':
            {
                if (!Check[3])
                    break;
        
                NextY += 1;
                if (!checkMap[_y][_x][3] && !checkMap[NextY][NextX][2])
                {
                    ++Count;
                    checkMap[_y][_x][3] = true;
                }
                break;
            }
        }

        _x = NextX;
        _y = NextY;
        ++_depth;
    }

    return;
}

int solution(string dirs)
{
    int answer = 0;

    DFS(5, 5, 0, dirs);

    answer = Count;
    return Count;
}

int main()
{
    solution("LULLLLLLU");

    return 0;
}