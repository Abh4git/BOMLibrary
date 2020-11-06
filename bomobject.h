#ifndef BOMOBJECT_H
#define BOMOBJECT_H
#include <../BOMLibrary/interface.h>
#include <../BOMLibrary/ModelIdentification.h>
#include <../BOMLibrary/conceptualmodeldefinition.h>
#include <QMetaType>
namespace BOMLIB
{
class BOMObject
{
public:
    BOMObject()
    {

    }

	//! Constructor
	/*!
		\param ModelIdentification* modelIdent (ModelIdentification object serves as Identity. All 
		BOM Objects refer to ModelIdentification).

	*/
    BOMObject(ModelIdentification* modelIdent)
    {
        qRegisterMetaType<Interface>("Interface");
        this->m_modelIdentify=modelIdent;
        this->m_interfaces = QList<Interface*>();

    }
	//! AddInterface
	/*!
		\param Interface* interface 
		Interfaces for communication or processing are added here.

	*/
    void AddInterface(Interface* interface)
    {
        this->m_interfaces.append(interface);
    }
	//! SetConceptualModel
	/*!
		\param ConceptualModelDefinition* conceptModel
		Associate a behavioural or conceptual model to BOM Object
	*/
    void SetConceptualModel(ConceptualModelDefinition* conceptModel)
    {
        this->m_conceptualModel=conceptModel;
    }
	//! GetConceptualModel
	/*!
		Returns the  behavioural or conceptual model assciated to the BOM Object
	*/
	ConceptualModelDefinition* GetConceptualModel()
    {
        return this->m_conceptualModel;
    }
	//! GetModelIdentification
	/*!
		Returns the ModelIdentification which serves as identifier for the BOM Object.
	*/
    ModelIdentification* GetModelIdentification()
    {
        return this->m_modelIdentify;
    }
	//! GetInterfaces
	/*!
		Returns the Interfaces associated with the BOM Object as a list.
	*/
    QList<Interface*> GetInterfaces()
    {
        return this->m_interfaces;
    }
	//! hasInterfaceSupport
	/*!
		Check and retrun if the interface is supported at all on the BOM Object Type.
	*/
	bool hasInterfaceSupport(Type interfaceType)
	{
		bool found=false;
		foreach(Interface* interfaceFilter,m_interfaces)
		{
			if(interfaceFilter->getTypeOfInterface()==interfaceType)
			{
				found=true;
				break;
			}
		}
		return found;
	}
 private:
    ModelIdentification* m_modelIdentify;
    QList<Interface*> m_interfaces;
    ConceptualModelDefinition* m_conceptualModel;
};



}

Q_DECLARE_METATYPE(BOMLIB::BOMObject)

#endif // BOMOBJECT_H
