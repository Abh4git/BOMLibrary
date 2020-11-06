///////////////////////////////////////////////////////////
//  Reference.cpp
//  Implementation of the Class Reference
//  Created on:      23-Aug-2012 5:58:55 PM
//  Original author: INABG
///////////////////////////////////////////////////////////

#include "Reference.h"

using namespace BOMLIB;
Reference::Reference(){

}



Reference::~Reference(){

}





QString Reference::GetIdentification(){

	return Identification;
}


QString Reference::GetType(){

	return Type;
}


void Reference::SetIdentification(QString newVal){

	Identification = newVal;
}


void Reference::SetType(QString newVal){

	Type = newVal;
}
