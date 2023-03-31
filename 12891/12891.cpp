


#include <iostream>

int main()
{
	int S, P;

	//ios_base::sync_with_stdio(false);
	//cout.tie(NULL);
	//cin.tie(NULL);

	std::string DNA;
	std::cin >> S >> P;

	int ACGTarr[4] = { 0 };
	int CurrentACGT[4] = { 0 };

	DNA.resize(S + 1, 0);

	for (int i = 0; i < S; ++i)
	{
		std::cin >> DNA[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		std::cin >> ACGTarr[i];
	}

	int Count = 0;

	int Start = 0;
	int End = P - 1;

	for (int i = Start; i < P; ++i)
	{
		switch (DNA[i])
		{
		case 'A':
			++CurrentACGT[0];
			break;
		case 'C':
			++CurrentACGT[1];
			break;
		case 'G':
			++CurrentACGT[2];
			break;
		case 'T':
			++CurrentACGT[3];
			break;
		}
	}

	bool bPwdCheck = true;

	for (int j = 0; j < 4; ++j)
	{
		if (ACGTarr[j] > CurrentACGT[j])
			bPwdCheck = false;
	}

	if (bPwdCheck)
		++Count;

	++Start;
	++End;

	while (End < S)
	{
		switch (DNA[End])
		{
		case 'A':
			++CurrentACGT[0];
			break;
		case 'C':
			++CurrentACGT[1];
			break;
		case 'G':
			++CurrentACGT[2];
			break;
		case 'T':
			++CurrentACGT[3];
			break;
		}


		switch (DNA[Start - 1])
		{
		case 'A':
			--CurrentACGT[0];
			break;
		case 'C':
			--CurrentACGT[1];
			break;
		case 'G':
			--CurrentACGT[2];
			break;
		case 'T':
			--CurrentACGT[3];
			break;
		}

		bool bPwdCheck = true;

		for (int j = 0; j < 4; ++j)
		{
			if (ACGTarr[j] > CurrentACGT[j])
				bPwdCheck = false;
		}

		if (bPwdCheck)
			++Count;

		++Start;
		++End;
	}

	std::cout << Count << "\n";

	return 0;
}