#include "state.h"


using namespace BOMLIB;

state::state(QString name)
{
    this->m_name=name;
}
QString state::GetName()
{
    return this->m_name;
}

exitCondition* state::GetExitCondition()
{
    return this->m_exitCondition;
}

void state::SetExitCondition(exitCondition *condition)
{
    this->m_exitCondition=condition;
}

void state::SetNextState(state *nextState)
{
    this->m_nextState=nextState;
}

