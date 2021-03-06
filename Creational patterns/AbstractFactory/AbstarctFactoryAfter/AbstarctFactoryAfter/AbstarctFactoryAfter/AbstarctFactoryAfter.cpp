// AbstarctFactoryAfter.cpp : Defines the entry point for the console application.
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
	virtual ~Parent() {};

	virtual void someAction() = 0;
	virtual void someAnotherAction() = 0;
};

//----------------------------------------------------------------

class ChildA1 : public Parent
{
public:
	virtual void someAction()
	{
		std::cout << "\nChildA1 someAction()";
	};

	virtual void someAnotherAction()
	{
		std::cout << "\nChildA1 someAnotherAction()";
	};
};

//----------------------------------------------------------------

class ChildA2 : public Parent
{
public:
	virtual void someAction()
	{
		std::cout << "\nChildA2 someAction()";
	};

	virtual void someAnotherAction()
	{
		std::cout << "\nChildA2 someAnotherAction()";
	};
};

//----------------------------------------------------------------

class ChildB1 : public Parent
{
public:
	virtual void someAction()
	{
		std::cout << "\nChildB1 someAction()";
	};

	virtual void someAnotherAction()
	{
		std::cout << "\nChildB1 someAnotherAction()";
	};
};

//----------------------------------------------------------------

class ChildB2 : public Parent
{
public:
	virtual void someAction()
	{
		std::cout << "\nChildB2 someAction()";
	};

	virtual void someAnotherAction()
	{
		std::cout << "\nChildB2 someAnotherAction()";
	};
};

//----------------------------------------------------------------

class Factory
{
public:
	virtual void someAction() = 0;
	virtual void someAnotherAction() = 0;

	std::vector<Parent*> objectVector;

	virtual ~Factory()
	{
		for (Parent* iterator : objectVector)
		{
			delete iterator;
		}
	};
};

//----------------------------------------------------------------

class FactoryChild1: public Factory
{
	virtual void someAction()
	{
		objectVector.push_back(new ChildA1);
		objectVector.push_back(new ChildB1);

		for (Parent* iterator : objectVector)
		{
			iterator->someAction();
		}
	};

	virtual void someAnotherAction()
	{
		objectVector.push_back(new ChildA1);
		objectVector.push_back(new ChildB1);

		for (Parent* iterator : objectVector)
		{
			iterator->someAnotherAction();
		}
	};
};

//----------------------------------------------------------------
class FactoryChild2: public Factory
{
	virtual void someAction()
	{
		objectVector.push_back(new ChildA2);
		objectVector.push_back(new ChildB2);

		for (Parent* iterator : objectVector)
		{
			iterator->someAction();
		}
	};

	virtual void someAnotherAction()
	{
		objectVector.push_back(new ChildA2);
		objectVector.push_back(new ChildB2);

		for (Parent* iterator : objectVector)
		{
			iterator->someAnotherAction();
		}
	};
};

//----------------------------------------------------------------

class Client
{
private:
	Factory* factoryObject;

public:
	Client(Factory* i_factoryObject)
	{
		factoryObject = i_factoryObject;
	};

	void someClientAction()
	{
		factoryObject->someAction();
	};

	void someClientAnotherAction()
	{
		factoryObject->someAnotherAction();
	};

	~Client()
	{
		delete factoryObject;
	};
};

//----------------------------------------------------------------

int main()
{
	Factory* factoryObject = nullptr;

#ifdef Child1
	factoryObject = new FactoryChild1();
#else
	factoryObject = new FactoryChild2();
#endif

	Client* object = new Client(factoryObject);

	object->someClientAction();
	object->someClientAnotherAction();

	delete object;

	std::system("pause");
	return 0;
}