///////////////////////////////////////////////////////////
//  Use History.cpp
//  Implementation of the Class Use History
//  Created on:      23-Aug-2012 5:58:56 PM
//  Original author: INABG
///////////////////////////////////////////////////////////

#include "UseHistory.h"

using namespace BOMLIB;

UseHistory::UseHistory(){

}



UseHistory::~UseHistory(){

}





QString UseHistory::GetUseHistoryVal(){

        return UseHistoryval;
}


void UseHistory::SetUseHistoryVal(QString newVal){

        UseHistoryval = newVal;
}
