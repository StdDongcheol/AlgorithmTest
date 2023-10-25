// 5052.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
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
    int T;

    std::cin >> T;

    while (T--)
    {
        std::vector<std::string> vecStr;
        MyNode* RootNode = new MyNode;
        bool NumberCheck = false;
        int N;
        std::cin >> N;

        for (int i = 0; i < N; ++i)
        {
            std::string str;
            std::cin >> str;
            vecStr.push_back(str);
        }

        std::sort(vecStr.begin(), vecStr.end());

        for (int i = 0; i < vecStr.size(); ++i)
        {
            std::string str = vecStr[i];

            // 현재 조사중인 노드와 반복자를 
            // 각 문자마다 검사하면서 갱신 및 노드 추가를 할거임.
            MyNode* CurNode = RootNode;
            auto iterBegin = CurNode->NodeList.begin();
            auto iterEnd = CurNode->NodeList.end();

            for (int j = 0; j < str.length(); ++j)
            {
                char CurChar = str[j];
                
                // 리스트내 노드가 아무것도 없을경우 추가 및 반복자 갱신
                if (iterBegin == iterEnd)
                {
                    MyNode* Node = new MyNode;
                    Node->Character = CurChar;

                    CurNode->NodeList.push_back(Node);
                    CurNode = Node;
                    iterBegin = CurNode->NodeList.begin();
                    iterEnd = CurNode->NodeList.end();
                }

                // 하나라도 있을 경우 trie 탐색수행
                else
                {
                    // 노드 내 리스트 문자 탐색
                    for (; iterBegin != iterEnd; ++iterBegin)
                    {
                        // 문자 일치할 경우
                        if (CurChar == (*iterBegin)->Character)
                        {
                            // 접두어라면 NumberCheck로 일관성X로 반복문 탈출
                            if ((*iterBegin)->IsNumber == true)
                            {
                                NumberCheck = true;
                                break;
                            }

                            // 반복자 갱신 및 현재 노드로 탐색중인 노드를 갱신 및 탈출
                            CurNode = *iterBegin;
                            iterBegin = CurNode->NodeList.begin();
                            iterEnd = CurNode->NodeList.end();
                            break;
                        }
                    }

                    // 현재 문자가 리스트 안에 없다면 추가 및 반복자 갱신
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

            // 현재 문자열 싹 돌았다면 해당 문자열 끝인 노드(CurNode)를 접두어 체크
            CurNode->IsNumber = true;

            // 접두어였을 경우 일관성X로 반복문 탈출
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
