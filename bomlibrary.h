#ifndef BOMLIBRARY_H
#define BOMLIBRARY_H


#include "bomlibrary_global.h"
#include <QMetaType>
#include <qdir.h>
#include <../BOMLibrary/bomadaptationreader.h>
#include <../BOMLibrary/IBOMTypeLoadInterface.h>


using namespace BOMLIB;

//! BOMLibrary Class 
	/*!
		Export Class used by applications accessing as a library to read the
		defintions from BOM XML files and obtain all the BOM Objects from
		a specified folder.
	*/
class BOMLIBRARY_EXPORT BOMLibrary : public QObject,public IBOMTypeLoadInterface
//class __declspec(dllexport) BOMLibrary
{
	Q_OBJECT

    Q_PLUGIN_METADATA(IID "indus.bom.library")
    Q_INTERFACES(IBOMTypeLoadInterface)
public:
	//! Constructor
	/*!
		\param QObject* parent (Inherited from QObject)
	*/
	BOMLibrary(QObject* parent=0)
	{
        qRegisterMetaType<BOMObject>("BOMObject");
	}
	//! Destructor
	~BOMLibrary()
	{
	}
	//! getCurrentDefintions method
	/*!
		Returns the BOM Objects read from sepcified folder as a list.
	*/
	 QList<BOMObject*> getCurrentDefintions()
	{
		return m_currentDefintions;
	}
	//! LoadDefinitions
	/*!
		\param QString relativeFolderName
		Loads the defintions from the folder 
	*/
	bool LoadDefinitions(QString relativeFolderName);
	
    BOMObject* FindBOMType(QString BOMTypeName);
		/*
	{
    foreach(BOMObject* bomType,  this->m_currentDefintions)
    {
        if (bomType->GetModelIdentification()->GetName()==BOMTypeName)
        {
            return bomType;
        }
    }
	} */


private:
	QList<BOMObject*> m_currentDefintions;
};

 


#endif // BOMLIBRARY_H


//extern "C" BOMLIBRARY_LIB BOMLibrary* getBOMLibrary();
