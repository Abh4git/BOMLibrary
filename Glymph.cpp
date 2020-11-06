///////////////////////////////////////////////////////////
//  Glymph.cpp
//  Implementation of the Class Glymph
//  Created on:      23-Aug-2012 5:57:27 PM
//  Original author: INABG
///////////////////////////////////////////////////////////

#include "Glymph.h"

using namespace BOMLIB;
Glymph::Glymph(){

}



Glymph::~Glymph(){

}





double Glymph::GetAlt(){

	return Alt;
}


double Glymph::GetHeight(){

	return Height;
}


QImage Glymph::GetImage(){

        return Image;
}


QString Glymph::GetType(){

	return Type;
}


double Glymph::GetWidth(){

	return Width;
}


void Glymph::SetAlt(double newVal){

	Alt = newVal;
}


void Glymph::SetHeight(double newVal){

	Height = newVal;
}


void Glymph::SetImage(QImage newVal){

        Image = newVal;
}


void Glymph::SetType(QString newVal){

	Type = newVal;
}


void Glymph::SetWidth(double newVal){

	Width = newVal;
}

void Glymph::SetFileName(QString fileName)
{
	m_FileName=fileName;
}
QString Glymph::GetFileName()
{
	return m_FileName;
}