// Prototype.cpp : Defines the entry point for the console application.
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
			switch (choise)
			{
				case 1:
				{
					object = new ChildA();
					break;
				}
				case 2:
				{
					object = new ChildB();
					break;
				}
				case 3:
				{
					object = new ChildC();
					break;
				}
				default:
				{
					std::cout << "\nWrong choise";
					continue;
				}
			}
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
	

    return 0;
}

