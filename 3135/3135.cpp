// 3135.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    int N;
    int A, B;
    
    std::cin >> A >> B;
    std::cin >> N;
    std::vector<int> vec(N);
    
    bool Check = false;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> vec[i];
        if (abs(vec[i] - B) < abs(A - B))
        {
            Check = true;
            A = vec[i];
        }
    }

    if (Check)
        std::cout << abs(A - B) + 1;
    else
        std::cout << abs(A - B);

    return 0;
}
