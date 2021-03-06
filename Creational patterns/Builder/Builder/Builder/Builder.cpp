// Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

//-----------------------------------------------------------------------

enum ActionType {Action_A, Action_B, Action_C};

//-----------------------------------------------------------------------

struct ConfigElement
{
	ActionType	m_actionType;
	std::size_t m_repeatTimes;
	std::string m_data;
};

//-----------------------------------------------------------------------

class ActionExecuter
{
private:
	std::string m_executeData;

public:
	ActionExecuter(std::string i_data): m_executeData (i_data) {};

	void executeAction_A(std::string i_configData)
	{
		std::cout << "\nAction_A: " << m_executeData + ": " + i_configData << "\n";
	};

	void executeAction_B(std::string i_configData)
	{
		std::cout << "\nAction_B: " << m_executeData + ": " + i_configData << "\n";
	};

	void executeAction_C(std::string i_configData)
	{
		std::cout << "\nAction_C: " << m_executeData + ": " + i_configData << "\n";
	};
};

//-----------------------------------------------------------------------

class AF_ActionTriggererParent
{
public:
	ActionExecuter* m_actionExecuter;
	AF_ActionTriggererParent() : m_actionExecuter(nullptr) {};

	virtual void triggerAction_A() = 0;
	virtual void triggerAction_B() = 0;
	virtual void triggerAction_C() = 0;
};

//-----------------------------------------------------------------------

class AF_ActionTriggererChild_A : public AF_ActionTriggererParent
{
public:
	AF_ActionTriggererChild_A()
	{
		m_actionExecuter = new ActionExecuter("AF_ActionTriggererChild_A");
	}

	~AF_ActionTriggererChild_A()
	{
		if (m_actionExecuter != nullptr)
			delete m_actionExecuter;
	};

	virtual void triggerAction_A()
	{
		m_actionExecuter->executeAction_A("triggerAction_A");
	}

	virtual void triggerAction_B()
	{
		m_actionExecuter->executeAction_B("triggerAction_B");
	}

	virtual void triggerAction_C()
	{
		m_actionExecuter->executeAction_C("triggerAction_C");
	}
};

//-----------------------------------------------------------------------

class AF_ActionTriggererChild_B : public AF_ActionTriggererParent
{
public:
	AF_ActionTriggererChild_B()
	{
		m_actionExecuter = new ActionExecuter("AF_ActionTriggererChild_B");
	}

	~AF_ActionTriggererChild_B()
	{
		if (m_actionExecuter != nullptr)
			delete m_actionExecuter;
	};

	virtual void triggerAction_A()
	{
		m_actionExecuter->executeAction_A("triggerAction_A");
	}

	virtual void triggerAction_B()
	{
		m_actionExecuter->executeAction_B("triggerAction_B");
	}

	virtual void triggerAction_C()
	{
		m_actionExecuter->executeAction_C("triggerAction_C");
	}
};

//-----------------------------------------------------------------------

class AF_ActionTriggererChild_C : public AF_ActionTriggererParent
{
public:
	AF_ActionTriggererChild_C()
	{
		m_actionExecuter = new ActionExecuter("AF_ActionTriggererChild_C");
	}

	~AF_ActionTriggererChild_C()
	{
		if (m_actionExecuter != nullptr)
			delete m_actionExecuter;
	};

	virtual void triggerAction_A()
	{
		m_actionExecuter->executeAction_A("triggerAction_A");
	}

	virtual void triggerAction_B()
	{
		m_actionExecuter->executeAction_B("triggerAction_B");
	}

	virtual void triggerAction_C()
	{
		m_actionExecuter->executeAction_C("triggerAction_C");
	}
};

//-----------------------------------------------------------------------

class Client
{
private:
	AF_ActionTriggererParent* m_triggerer;
	std::vector<ConfigElement> m_configVector;

public:
	void setTriggerer(AF_ActionTriggererParent* i_triggerer)
	{
		m_triggerer = i_triggerer;
	};

	void startTriggeringActions()
	{
		for (const auto& configIterator : m_configVector)
		{
			switch (configIterator.m_actionType)
			{
				case Action_A:
				{
					for (std::size_t repeatIter = 0; repeatIter < configIterator.m_repeatTimes; repeatIter++)
					{
						m_triggerer->triggerAction_A();
					}
				}
				case Action_B:
				{
					for (std::size_t repeatIter = 0; repeatIter < configIterator.m_repeatTimes; repeatIter++)
					{
						m_triggerer->triggerAction_B();
					}
				}
				case Action_C:
				{
					for (std::size_t repeatIter = 0; repeatIter < configIterator.m_repeatTimes; repeatIter++)
					{
						m_triggerer->triggerAction_C();
					}
				}
			default:
				break;
			}

		}
	};

	void setConfiguration(std::vector<ConfigElement>& i_configVector)
	{
		m_configVector = i_configVector;
	};
};

//-----------------------------------------------------------------------

int main()
{
	std::vector<AF_ActionTriggererParent*> triggererVector { 
		new AF_ActionTriggererChild_A(), 
		new AF_ActionTriggererChild_B(), 
		new AF_ActionTriggererChild_C() };

	std::vector<ConfigElement> configuration{
		ConfigElement{Action_A, 1, "data 1"}, 
		ConfigElement{ Action_B, 2, "data 2" }, 
		ConfigElement{ Action_C, 3, "data 3" } };
				
	Client* client = new Client();
	client->setConfiguration(configuration);

	for (AF_ActionTriggererParent* triggerIter : triggererVector)
	{
		std::cout << "\n\nTrigger";
		client->setTriggerer(triggerIter);
		client->startTriggeringActions();
	}
	
	std::system("pause");
    return 0;
}

