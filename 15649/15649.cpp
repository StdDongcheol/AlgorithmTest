// 15649.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int N, M;
bool Check[9];

void Func(int _Count, std::vector<int> _vec)
{
	if (_Count == M)
	{
		for (int i = 0; i < _vec.size(); ++i)
		{
			std::cout << _vec[i] << " ";
		}

		std::cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!Check[i])
		{
			Check[i] = true;
			_vec.push_back(i);
			Func(_Count + 1, _vec);
			_vec.pop_back();
			Check[i] = false;
		}
	}
}

int main()
{
	std::cin >> N >> M;
	std::vector<int> vec;
	Func(0, vec);

}
