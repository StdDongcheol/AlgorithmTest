// 11723.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

char cmd[10];
int main()
{
    int N, S = 0;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int Numb;

        std::cin >> cmd;


        if (strcmp(cmd, "all") == 0)
        {   
            S = (S | ~((int)(0)));
        }
        else if (strcmp(cmd, "empty") == 0)
        {
            S = (S & 0);
        }
        else
        {
            std::cin >> Numb;

            if (strcmp(cmd, "add") == 0)
            {
                S |= (1 << Numb);
            }
            else if (strcmp(cmd, "toggle") == 0)
            {
                S = (S ^ (1 << Numb));
            }
            else if (strcmp(cmd, "remove") == 0)
            {
                S = (S & ~(1 << Numb));
            }
            else if (strcmp(cmd, "check") == 0)
            {
                if (S & (1 << Numb))
                    std::cout << 1 << '\n';
                else
                    std::cout << 0 << '\n';
            }
        }
    }

}
