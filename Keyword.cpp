///////////////////////////////////////////////////////////
//  Keyword.cpp
//  Implementation of the Class Keyword
//  Created on:      23-Aug-2012 5:58:50 PM
//  Original author: INABG
///////////////////////////////////////////////////////////

#include "Keyword.h"

using namespace BOMLIB;
Keyword::Keyword(){

}



Keyword::~Keyword(){

}





QString Keyword::GetKeywordValue(){

        return KeywordValue;
}


QString Keyword::GetTaxonomy(){

	return Taxonomy;
}


void Keyword::SetKeywordValue(QString newVal){

        KeywordValue = newVal;
}


void Keyword::SetTaxonomy(QString newVal){

	Taxonomy = newVal;
}
