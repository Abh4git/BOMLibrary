#ifndef BOMADAPTATIONREADER_H
#define BOMADAPTATIONREADER_H
#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QDir>
#include <../BOMLibrary/interface.h>
#include "../BOMLibrary/conceptualmodeldefinition.h"
#include "../BOMLibrary/bomobject.h"
namespace BOMLIB
{
//! BOMAdaptationReader Class 
	/*! Responsibility : Prasers and reads the Base Object Model 
	based XML files to create BOM Object Types */
class BOMAdaptationReader
{
public:
	//! Constructor
	/*!
		\param filename name of the file to be Read by 
	*/
    BOMAdaptationReader(QString filename);
	//! SetDirectory
	/*!
		\param directoryName name of the folder file exists
	*/
    bool SetDirectory(QString directoryName);
	//! ReadDefinitions
	/*!
		Performs the Read from XML file
	*/
    bool ReadDefintions();
    //! GetModelObject
	/*!
		After ReadDefinitions method is called the ModelObject representation
		is returned by this method.
	*/
	ModelIdentification* GetModelObject();
    //! GetBOMObject
	/*!
		After ReadDefinitions method is called the BOMObject logical model is
		returned by this method.
	*/
	BOMObject* GetBOMObject();
private:
	//! ReadInterfaces
	/*!
		Called from ReadDefinitions method this method read in the interfaces and returns
		them as a list.
	*/
    QList<Interface*> ReadInterfaces();
	//! ReadConceptualModel
	/*!
		Called from ReadDefinitions method this method read in behavioural model or conceptual model.
	*/
    ConceptualModelDefinition* ReadConceptualModel();
	//! Private Variables
	QString filename;
    QFile file;
    QXmlStreamReader reader;
    QDir dir;
    ModelIdentification* _currentModelObject;
    ConceptualModelDefinition* _currentConceptualModel;
    BOMObject* _currentBOMObject;
    stateMachine* _currentStateMachine;
};

}

#endif // BOMADAPTATIONREADER_H
