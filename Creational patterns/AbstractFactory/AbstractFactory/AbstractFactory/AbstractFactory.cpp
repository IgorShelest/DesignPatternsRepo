// AbstractFactory.cpp : Defines the entry point for the console application.
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

class Client
{
private:
	std::vector<Parent*> objectVector;

public:
	void someClientAction()
	{
#ifdef Child1
		objectVector.push_back(new ChildA1);
		objectVector.push_back(new ChildB1);
#else
		objectVector.push_back(new ChildA2);
		objectVector.push_back(new ChildB2);
#endif

		for (Parent* iterator : objectVector)
		{
			iterator->someAction();
		}
	};

	void someClientAnotherAction()
	{
#ifdef Child1
		objectVector.push_back(new ChildA1);
		objectVector.push_back(new ChildB1);
#else
		objectVector.push_back(new ChildA2);
		objectVector.push_back(new ChildB2);
#endif

		for (Parent* iterator : objectVector)
		{
			iterator->someAnotherAction();
		}
	};

	~Client()
	{
		for (Parent* iterator : objectVector)
		{
			delete iterator;
		}
	};
};

//----------------------------------------------------------------

int main()
{
	Client* object = new Client();

	object->someClientAction();
	object->someClientAnotherAction();

	delete object;

	std::system("pause");
	return 0;
}