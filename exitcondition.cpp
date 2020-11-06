#include "exitcondition.h"

using namespace BOMLIB;

exitCondition::exitCondition()
{

}

void exitCondition::SetExitAction(QString exitAction)
{
    this->m_exitAction=exitAction;
}

void exitCondition::SetNextState(QString nextState)
{
    this->m_NextState=nextState;
}

QString exitCondition::GetExitAction()
{
    return m_exitAction;

}

QString exitCondition::GetNextState()
{
    return m_NextState;
}
