


#include <iostream>
#include "MyList.h"


int main()
{
	MyList* List = new MyList;
	List->insert("01082940701");
	List->insert("01057300701");
	List->insert("01012345678");
	List->insert("01099998888");
	List->insert("01077778888");




	std::cout << "\n========== Print All ========== \n";
	List->printAll();

	std::cout << "========== find(\"01012345678\") ========== \n";
	
	{
		MyNode* Node = List->find("01012345678");
		if (Node != nullptr)
			printf("%s", Node->Data);
	}

	std::cout << "\n========== Print All ========== \n";
	List->printAll();

	std::cout << "========== erase(\"01099998888\") ========== \n";
	
	List->erase("01099998888");

	{
		MyNode* Node = List->find("01099998888");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
		else
			std::cout << "Cannot Finded 01099998888 ! \n";
	}


	std::cout << "\n========== insert(01082229999) ========== \n";
	List->insert("01082229999");

	std::cout << "========== find(\"01082229999\") ========== \n";

	{
		MyNode* Node = List->find("01082229999");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
	}

	std::cout << "\n========== insert(01075757575) ========== \n";
	List->insert("01075757575");


	std::cout << "========== find(\"01082229999\") ========== \n";

	{
		MyNode* Node = List->find("01075757575");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
	}

	std::cout << "\n========== Print All ========== \n";
	List->printAll();

	std::cout << "\n========== Adjust 01057300701 to 01066768142 ========== \n";
	List->adjust("01057300701", "01066768142");



	std::cout << "========== find(\"01066768142\") ========== \n";

	{
		MyNode* Node = List->find("01066768142");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
	}



	std::cout << "\n========== Print All ========== \n";
	List->printAll();



	std::cout << "========== erase(\"01066768142\") ========== \n";

	List->erase("01066768142");

	{
		MyNode* Node = List->find("01066768142");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
		else
			std::cout << "Cannot Finded 01066768142 ! \n";
	}


	std::cout << "\n========== Print All ========== \n";
	List->printAll();

	
	std::cout << "\n========== Erase All ========== \n";
	List->eraseAll();


	std::cout << "\n========== Print All ========== \n";
	List->printAll();


	std::cout << "\n========== Insert New ========== \n";
	List->printAll();

	List->insert("01082940701");
	List->insert("01057300701");
	List->insert("01012345678");
	List->insert("01066768142");
	List->insert("01077778888");

	std::cout << "\n========== Print All ========== \n";
	List->printAll();


	std::cout << "========== find(\"01066768142\") ========== \n";

	{
		MyNode* Node = List->find("01066768142");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
	}


	std::cout << "\n========== erase(01082940701) ========== \n";
	List->erase("01082940701");

	{
		MyNode* Node = List->find("01082940701");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
		else
			std::cout << "Cannot Founded 01082940701! \n";
	}


	std::cout << "========== find(\"01066768142\") ========== \n";

	{
		MyNode* Node = List->find("01066768142");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
	}


	std::cout << "========== insert(\"01022222222\") ========== \n";

	List->insert("01022222222");


	std::cout << "========== find(\"01057300701\") ========== \n";

	{
		MyNode* Node = List->find("01057300701");
		if (Node != nullptr)
			printf("%s\n", Node->Data);
	}


	std::cout << "\n========== Print All ========== \n";
	List->printAll();


	return 0;
}