// Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//-------------------------------------------------------

#include <iostream>
#include <iomanip>

//-------------------------------------------------------

class Singleton
{
private:
	Singleton() : m_data(0)
	{
		std::cout << "\nCTOR called";
	};

	static Singleton*	s_instancePtr;
	std::size_t			m_data;

public:
	static Singleton* getInstance()
	{
		if (!s_instancePtr)
		{
			s_instancePtr = new Singleton();
		}

		return s_instancePtr;
	};

	std::size_t getValue()
	{
		return m_data;
	};

	void setValue(std::size_t i_data)
	{
		m_data = i_data;
	};
};

//-------------------------------------------------------

Singleton* Singleton::s_instancePtr = nullptr;

//-------------------------------------------------------

int main()
{
	std::cout << "\nDefault m_data = " << Singleton::getInstance()->getValue();

	Singleton::getInstance()->setValue(1);
	std::cout << "\nAfter setValue() m_data = " << Singleton::getInstance()->getValue();


	std::cout << "\n";
	std::system("pause");
	return 0;
}

