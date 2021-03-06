// PrototypeAfter.cpp : Defines the entry point for the console application.
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
	virtual Parent* clone() = 0;
};

//----------------------------------------------------------------

class ChildA : public Parent
{
public:
	virtual void someAction()
	{
		std::cout << "\nChildA someAction()";
	};

	virtual Parent* clone()
	{
		return new ChildA();
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

	virtual Parent* clone()
	{
		return new ChildB();
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
	
	virtual Parent* clone()
	{
		return new ChildC();
	};

};

//----------------------------------------------------------------

class Factory
{
private:
	static std::vector<Parent*> m_prototypeVector;

public:
	static Parent* getObject(std::size_t i_object)
	{
		return m_prototypeVector.at(i_object)->clone();
	};
};

//----------------------------------------------------------------

std::vector<Parent*> Factory::m_prototypeVector = {new ChildA, new ChildB, new ChildC};

//----------------------------------------------------------------

int main()
{
	std::vector< Parent* > objectVector;
	size_t choise;

	while (true)
	{
		std::cout << "\n[1] ChildA \n[2] ChildB \n[3] ChildC";
		std::cout << "\nEnter what to create:";

		if (std::cin >> choise)
		{
			if (choise > 3 || choise < 1)
			{
				std::cout << "\nChoise is wrong";
				continue;
			}

			Parent* object = Factory::getObject(choise - 1);
			objectVector.push_back(object);
		}
		else
		{
			std::cout << "\nWrong choise type entered";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}
		
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