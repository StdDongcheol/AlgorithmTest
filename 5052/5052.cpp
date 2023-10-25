// 5052.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <list>

struct MyNode
{
    bool IsNumber = false;
    char Character;
    std::list<MyNode*> NodeList;
};

int main()
{
    int T, N;

    std::cin >> T;

    while (T--)
    {
        std::cin >> N;
        MyNode* RootNode = new MyNode;

        bool NumberCheck = false;
        for (int i = 0; i < N; ++i)
        {
            std::string str;
            std::cin >> str;

            MyNode* CurNode = RootNode;
            auto iterBegin = CurNode->NodeList.begin();
            auto iterEnd = CurNode->NodeList.end();

            for (int j = 0; j < str.length(); ++j)
            {
                char CurChar = str[j];
                
                if (iterBegin == iterEnd || (*iterBegin)->NodeList.empty())
                {
                    if (iterBegin != iterEnd && (*iterBegin)->IsNumber == true)
                    {
                        if (CurChar == (*iterBegin)->Character)
                        {
                            NumberCheck = true;
                            break;
                        }
                    }

                    MyNode* Node = new MyNode;
                    Node->Character = CurChar;

                    CurNode->NodeList.push_back(Node);
                    CurNode = Node;
                    iterBegin = CurNode->NodeList.begin();
                    iterEnd = CurNode->NodeList.end();
                }

                else
                {
                    for (; iterBegin != iterEnd; ++iterBegin)
                    {
                        if (CurChar == (*iterBegin)->Character)
                        {
                            if ((*iterBegin)->IsNumber == true)
                            {
                                NumberCheck = true;
                                break;
                            }

                            CurNode = *iterBegin;
                            iterBegin = CurNode->NodeList.begin();
                            iterEnd = CurNode->NodeList.end();
                            break;
                        }
                    }

                    if (iterBegin == iterEnd)
                    {
                        MyNode* Node = new MyNode;
                        Node->Character = CurChar;

                        CurNode->NodeList.push_back(Node);
                        CurNode = Node;
                        iterBegin = CurNode->NodeList.begin();
                        iterEnd = CurNode->NodeList.end();
                    }

                    if (NumberCheck)
                        break;
                }
            }

            CurNode->IsNumber = true;
            if (NumberCheck)
                break;
        }
        if (NumberCheck)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }

    return 0;
}
