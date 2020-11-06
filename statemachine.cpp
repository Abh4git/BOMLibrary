#include "statemachine.h"

using namespace BOMLIB;

stateMachine::stateMachine(QString name)
{
    this->m_Name=name;
    m_StatesList= QList<state*> ();

}
void stateMachine::AddState(state* stateToAdd)
{
    this->m_StatesList.append(stateToAdd);
}

void stateMachine::AddEntity(QString entity)
{
    this->m_Entities.append(entity);
}

QList<state*> stateMachine::GetStatesList()
{
    return m_StatesList;
}

QString stateMachine::GetName()
{
    return this->m_Name;
}
