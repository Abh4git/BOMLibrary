///////////////////////////////////////////////////////////
//  POC.cpp
//  Implementation of the Class POC
//  Created on:      23-Aug-2012 5:58:54 PM
//  Original author: INABG
///////////////////////////////////////////////////////////

#include "POC.h"

using namespace BOMLIB;
POC::POC(){

}



POC::~POC(){

}





QString POC::GetEmail(){

	return Email;
}


QString POC::GetName(){

	return Name;
}


QString POC::GetOrg(){

	return Org;
}


QString POC::GetTelephone(){

	return Telephone;
}


QString POC::GetType(){

	return Type;
}


void POC::SetEmail(QString newVal){

	Email = newVal;
}


void POC::SetName(QString newVal){

	Name = newVal;
}


void POC::SetOrg(QString newVal){

	Org = newVal;
}


void POC::SetTelephone(QString newVal){

	Telephone = newVal;
}


void POC::SetType(QString newVal){

	Type = newVal;
}
