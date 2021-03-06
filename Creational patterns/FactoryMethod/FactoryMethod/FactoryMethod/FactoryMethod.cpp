// FactoryMethod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//----------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <vector>

//----------------------------------------------------------------

class Parent
{
public:
	virtual void someAction() = 0;
	static Parent* factoryMethod(std::size_t i_choise);
};

//----------------------------------------------------------------

class ChildA : public Parent
{
public:
	virtual void someAction()
	{
		std::cout << "\nChildA someAction()";
	};
};

//----------------------------------------------------------------

class ChildB : public Parent
{
public:
	virtual void someAction()
	{
		std::cout << "\nChildB someAction()";
	};
};

//----------------------------------------------------------------

class ChildC : public Parent
{
public:
	virtual void someAction()
	{
		std::cout << "\nChildC someAction()";
	};
};

//----------------------------------------------------------------

Parent* Parent::factoryMethod(std::size_t i_choise)
{
	Parent* objectToReturn = nullptr;

	switch (i_choise)
	{
		case 1:
		{
			objectToReturn = new ChildA();
			break;
		}
		case 2:
		{
			objectToReturn = new ChildB();
			break;
		}
		case 3:
		{
			objectToReturn = new ChildC();
			break;
		}
	}

	return objectToReturn;
};

//----------------------------------------------------------------

int main()
{
	std::vector< Parent* > objectVector;
	size_t choise;

	while (true)
	{
		std::cout << "\n[1] ChildA \n[2] ChildB \n[3] ChildC";
		std::cout << "\nEnter what to create:";

		Parent* object = nullptr;

		if (std::cin >> choise)
		{
			object = Parent::factoryMethod(choise);
		}
		else
		{
			std::cout << "\nWrong choise type entered";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}

		objectVector.push_back(object);

		std::cout << "\nContinue? (y/n)";

		char continueDecision;
		std::cin >> continueDecision;

		if (continueDecision != 'y')
		{
			break;
		}
	}

	for (Parent* iterator : objectVector)
	{
		iterator->someAction();
	}

	for (Parent* iterator : objectVector)
	{
		delete iterator;
	}

	std::system("pause");
	return 0;
}