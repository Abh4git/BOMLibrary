///////////////////////////////////////////////////////////
//  Model Identification.cpp
//  Implementation of the Class Model Identification
//  Created on:      23-Aug-2012 5:58:52 PM
//  Original author: INABG
///////////////////////////////////////////////////////////

#include "ModelIdentification.h"

using namespace BOMLIB;
ModelIdentification::ModelIdentification(){
    m_ReferenceList= QList<Reference*>();
    m_POCList= QList<POC*>();
    m_GlymphList= QList<Glymph*>();
    m_KeywordList= QList<Keyword*>();
    m_UseHistoryList= QList<UseHistory*>();
    m_Type=0;
}



ModelIdentification::~ModelIdentification(){

}


//container implemented

void ModelIdentification::AddPOC(POC* poc)
{
    this->m_POCList.append(poc);

}

QList<Glymph*> ModelIdentification:: getGlymphList()
{
	return this->m_GlymphList;
}
void ModelIdentification::AddGlymph(Glymph* pic)
{
    this->m_GlymphList.append(pic);

}

void ModelIdentification::AddReference(Reference* ref)
{
    this->m_ReferenceList.append(ref);
}

void ModelIdentification:: AddUseHistory(UseHistory* useHist)
{
    this->m_UseHistoryList.append(useHist);
}

void ModelIdentification:: AddKeyword(Keyword* keyword)
{
    this->m_KeywordList.append(keyword);
}

void ModelIdentification::AddInterface(Interface* inf)
{
    this->m_Interfaces.append(inf);
}



QString ModelIdentification::GetApplicationDomain(){

        return ApplicationDomain;
}


QString ModelIdentification::GetDescription(){

	return Description;
}


QString ModelIdentification::GetModificationDate(){

        return ModificationDate;
}

QImage ModelIdentification::GetToolboxImage()
{

	return this->m_GlymphList.at(0)->GetImage();
}

QString ModelIdentification::GetToolBoxImageFileName()
{
	return this->m_GlymphList.at(0)->GetFileName();
}

QString ModelIdentification::GetToolBoxImageFileNameWithExtension()
{
	return this->m_GlymphList.at(0)->GetFileName() + "." + this->m_GlymphList.at(0)->GetType();
}

QSize ModelIdentification::GetToolBoxImageSize()
{
	
	return QSize(this->m_GlymphList.at(0)->GetWidth(),this->m_GlymphList.at(0)->GetHeight());
		//this->m_GlymphList.at(0)->GetImage().size();
}

QString ModelIdentification::GetSceneImageFileName()
{
	return this->m_GlymphList.at(1)->GetFileName();
}

QImage ModelIdentification::GetSceneImage()
{
	return this->m_GlymphList.at(1)->GetImage();
}
QString ModelIdentification::GetName(){

	return Name;
}

QSize ModelIdentification::GetSceneImageSize()
{
	 	return QSize(this->m_GlymphList.at(1)->GetWidth(),this->m_GlymphList.at(1)->GetHeight()); 
		//this->m_GlymphList.at(1)->GetImage().size();
}
QString ModelIdentification::GetSceneImageFileNameWithExtension()
{
	return this->m_GlymphList.at(1)->GetFileName() + "." + this->m_GlymphList.at(1)->GetType();
}

QString ModelIdentification::GetSceneImageStateChangedFileNameWithExtension()
{
	return this->m_GlymphList.at(2)->GetFileName() + "." + this->m_GlymphList.at(2)->GetType();
}


int ModelIdentification::GetOther(){

	return Other;
}


QString ModelIdentification::GetPurpose(){

	return Purpose;
}


QString ModelIdentification::GetReleaseRestriction(){

	return ReleaseRestriction;
}


QString ModelIdentification::GetSecurityClassification(){

        return SecurityClassification;
}


int ModelIdentification::GetBOMType(){

    return m_Type;
}


int ModelIdentification::GetUseLimitation(){

        return UseLimitation;
}


double ModelIdentification::GetVersion(){

	return Version;
}


void ModelIdentification::SetApplicationDomain(QString newVal){

        ApplicationDomain = newVal;
}


void ModelIdentification::SetDescription(QString newVal){

	Description = newVal;
}


void ModelIdentification::SetModificationDate(QString newVal){

        ModificationDate = newVal;
}


void ModelIdentification::SetName(QString newVal){

	Name = newVal;
}


void ModelIdentification::SetOther(int newVal){

	Other = newVal;
}


void ModelIdentification::SetPurpose(QString newVal){

	Purpose = newVal;
}


void ModelIdentification::SetReleaseRestriction(QString newVal){

	ReleaseRestriction = newVal;
}


void ModelIdentification::SetSecurityClassification(QString newVal){

        SecurityClassification = newVal;
}


void ModelIdentification::SetBOMType(int newVal){

    m_Type = newVal;
}




void ModelIdentification::SetUseLimitation(int newVal){

        UseLimitation = newVal;
}


void ModelIdentification::SetVersion(double newVal){

	Version = newVal;
}

//contained objects
//Q_EXPORT_PLUGIN2(BOMLIBRARY_EXPORT, ModelIdentification)
