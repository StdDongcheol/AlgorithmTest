#include <iostream>

int main()
{
    int L, A, B, C, D;
    int day = 0;
    std::cin >> L;
    std::cin >> A;
    std::cin >> B;
    std::cin >> C;
    std::cin >> D;

    int KorDay;
    int MathDay;

    if (A % C != 0)
        KorDay = (A / C) + 1;

    else
        KorDay = A / C;


    if (B % D != 0)
        MathDay = (B / D) + 1;

    else
        MathDay = B / D;

    day = KorDay > MathDay ? KorDay : MathDay;

    std::cout << L - day;

    return 0;
}