#include "conceptualmodeldefinition.h"

using namespace BOMLIB;

ConceptualModelDefinition::ConceptualModelDefinition()
{

}

void ConceptualModelDefinition::SetStateMachine(stateMachine *stateMachineofModel)
{
    this->m_stateMachine=stateMachineofModel;
}

stateMachine* ConceptualModelDefinition::GetStateMachine()
{
    return this->m_stateMachine;
}

