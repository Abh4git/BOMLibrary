#include "bomadaptationreader.h"
#include "bomobject.h"
#include "statemachine.h"
#include "state.h"
#include "exitcondition.h"
#include <qpixmap.h>
using namespace BOMLIB;

BOMAdaptationReader::BOMAdaptationReader(QString fileName)
{
    this->filename=fileName;
}

bool BOMAdaptationReader::ReadDefintions()
{
    QString id;
    QString name;
    QString desc;
    this->filename=dir.absoluteFilePath(this->filename);
    this->file.setFileName(this->filename);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        return false;
    }
    reader.setDevice(&this->file);

    ModelIdentification* modelObj=GetModelObject();
    //BOMObject* obj= new BOMObject(this->_currentModelObject);
    //this->_currentBOMObject=obj;
    name=this->_currentModelObject->GetName();
    desc=this->_currentModelObject->GetDescription();
    QString stateMachine1= this->_currentBOMObject->GetConceptualModel()->GetStateMachine()->GetName();
    this->file.close();
    return true;
}

 bool BOMAdaptationReader::SetDirectory(QString directoryName)
{
    QDir direct(directoryName);
    this->dir=direct;
    return true;
}

 //ModelIdentification
ModelIdentification* BOMAdaptationReader::GetModelObject()
{
    this->_currentModelObject= new ModelIdentification();
    QString prevRead="";

    while(!reader.atEnd() && !reader.hasError())
    {
        QString id;
        QString name;
        QXmlStreamAttributes attribs;
        QXmlStreamReader::TokenType token = reader.readNext();
        reader.setNamespaceProcessing(true);
        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument) {
                            continue;
        }
        /* If token is StartElement, we'll see if we can read it.*/
        if(token == QXmlStreamReader::StartElement)
        {
            if(reader.name()=="modelIdentification")
            {
                reader.readNextStartElement();
            }

           if(reader.qualifiedName() == "modelID:name" )
            {
               prevRead=="modelID:name";
                this->_currentModelObject ->SetName(reader.readElementText());
                reader.readNextStartElement();
            }
           if(reader.qualifiedName() == "modelID:type" )
            {
               QString text=reader.readElementText();

               int typeValue=0;
               if (text== "BOM1")
               {
                   typeValue=1;
               }
               else if (text=="BOM2")
               {
                   typeValue=2;
               }
               else if(text=="BOM3")
               {
                   typeValue=3;

               }
               else if(text=="BOM4")
               {
                   typeValue=4;

               }
               else if(text=="BOM5")
               {
                   typeValue=5;

               }
               if (this->_currentModelObject->GetBOMType()==0)
               {
               this->_currentModelObject->SetBOMType(typeValue);
               }
               reader.readNextStartElement();

            }
           if(reader.qualifiedName() == "modelID:version" )
            {

               this->_currentModelObject->SetVersion(reader.readElementText().toDouble());
               reader.readNextStartElement();
            }
           if(reader.qualifiedName() == "modelID:modificationDate" )
            {
               this->_currentModelObject->SetModificationDate(reader.readElementText());
               reader.readNextStartElement();

            }
           if(reader.qualifiedName() == "modelID:securityClassification" )
            {
               this->_currentModelObject->SetSecurityClassification(reader.readElementText());
               reader.readNextStartElement();

            }
           if(reader.qualifiedName() == "modelID:releaseRestriction" )
            {

               this->_currentModelObject->SetReleaseRestriction(reader.readElementText());
               reader.readNextStartElement();
            }
           if(reader.qualifiedName() == "modelID:purpose" )
            {
               this->_currentModelObject->SetPurpose(reader.readElementText());
               reader.readNextStartElement();

            }
           if(reader.qualifiedName() == "modelID:applicationDomain" )
            {

               this->_currentModelObject->SetApplicationDomain(reader.readElementText());
               reader.readNextStartElement();
            }
           if(reader.qualifiedName() == "modelID:description" )
            {
               this->_currentModelObject->SetDescription(reader.readElementText());
               reader.readNextStartElement();

            }
		   if(reader.qualifiedName() == "modelID:useLimitation" )
            {
               this->_currentModelObject->SetUseLimitation(reader.readElementText().toInt());
               reader.readNextStartElement();

            }
		   if(reader.qualifiedName() == "modelID:useHistory" )
            {
               //this->_currentModelObject->setuseHistory(reader.readElementText().toInt()); 
			//TODO: Modify modelIdentification to add setUseHistory (as it is only once)
               reader.readNextStartElement();

            }

		   if(reader.qualifiedName() == "modelID:keyword" )
            {
               Keyword* keyword= new Keyword;
			   reader.readNextStartElement();
			   keyword->SetTaxonomy(reader.readElementText());
			   reader.readNextStartElement();
			   keyword->SetKeywordValue(reader.readElementText());
			   this->_currentModelObject->AddKeyword(keyword);	


            }
		   if(reader.qualifiedName() == "modelID:poc" )
            {
               POC* poc= new POC;
			   reader.readNextStartElement();
			   poc->SetType(reader.readElementText());
			   reader.readNextStartElement();
			   poc->SetName(reader.readElementText());
			   reader.readNextStartElement();
			   poc->SetOrg(reader.readElementText());
			   reader.readNextStartElement();
			   poc->SetTelephone(reader.readElementText());
			   reader.readNextStartElement();
			   poc->SetEmail(reader.readElementText());
			   this->_currentModelObject->AddPOC(poc);	


            }
		   if(reader.qualifiedName() == "modelID:glymph" )
            {

               Glymph* glymph= new Glymph;
			   reader.readNextStartElement();
			   glymph->SetAlt(reader.readElementText().toInt());
			   reader.readNextStartElement();
			   glymph->SetHeight(reader.readElementText().toInt());
			   reader.readNextStartElement();
			   QString gfileName=reader.readElementText();
			   //QString iconImage=":/icons/Icons/"+ gfileName + ".ico";
			   QString iconImage="";
			   if (this->_currentModelObject->getGlymphList().count()<=2)
			   {
				iconImage=":/icons/"+ gfileName + ".ico";
			   } else
			   {
				 iconImage=":/images/"+ gfileName + ".png";
			   }
			   //QPixmap* pixmp=new QPixmap(":/icons/Icons/trafo.ico");
			   glymph->SetFileName(gfileName);
			   QPixmap* pixmp=new QPixmap(iconImage);
			   glymph->SetImage(pixmp->toImage());
			   reader.readNextStartElement();
			   glymph->SetType(reader.readElementText());
			   reader.readNextStartElement();
			   glymph->SetWidth(reader.readElementText().toInt());
			   this->_currentModelObject->AddGlymph(glymph);	
			}

           if (reader.name()=="conceptualModelDefinition")
           {
               this->_currentBOMObject=new BOMObject(this->_currentModelObject);
               this->_currentConceptualModel= ReadConceptualModel();
               this->_currentBOMObject->SetConceptualModel(this->_currentConceptualModel);


           }
           /*
           if (reader.name()=="Interfaces")
           {
               continue;
               //reader.readNextStartElement();
           }
           if(reader.name()=="Interface")
           {
               QList<Interface*> interfacesList= this->ReadInterfaces();

               foreach(Interface* supportedInf,interfacesList)
               {
                   this->_currentBOMObject->AddInterface(supportedInf);
               }
           }
           */
        }
    }
        //_currentDevice->SetIcon(QIcon(":/new/icons/Melody1.ico"));
        return this->_currentModelObject;

}

QList<Interface*> BOMAdaptationReader::ReadInterfaces()
{

    QList<Interface*> interfacesList;

        //QXmlStreamReader::TokenType token ;
        interfacesList=QList<Interface*>();
        while(reader.name()!="Interfaces" && (!reader.isEndElement())  && (!reader.atEnd()))
        {
            QXmlStreamAttributes attribsArg= reader.attributes();
            int id=0;
            QString name="";
            int type=0;
            if (attribsArg.count()>0 && reader.name()=="Interface")
            {

            QString arguments="";
            if (attribsArg.hasAttribute("id"))
            {
                id=attribsArg.value("id").toString().toInt();
            }
            if (attribsArg.hasAttribute("name"))
            {
                name=attribsArg.value("name").toString();
            }
            if (attribsArg.hasAttribute("Type"))
            {
                type=attribsArg.value("Type").toString().toInt();
            }

            if ( name!="")
            {
                Interface* interf1;
                if (type==0)
                {
                    interf1=new Interface(id,name,BOMLIB::Storage);

                } else if (type==1)
                {
                    interf1=new Interface(id,name,BOMLIB::Commmunication);
                }
                else if (type==2)
                {
                    interf1=new Interface(id,name,BOMLIB::OperatingSystem);
                }
				else if (type==3)
                {
                    interf1=new Interface(id,name,BOMLIB::Processor);
                }
				else if (type==4)
                {
                    interf1=new Interface(id,name,BOMLIB::Field);
                }
				else if (type==5)
                {
                    interf1=new Interface(id,name,BOMLIB::IEC61850LNClass);
                }
				else if (type==6)
                {
                    interf1=new Interface(id,name,BOMLIB::ProcessObjectClass);
                }
                interfacesList.append(interf1);
            }
            }
            reader.readNext();

        }
        return interfacesList;

}

ConceptualModelDefinition* BOMAdaptationReader::ReadConceptualModel()
{
    QString nameofstateMachine;
    QString stateName;
    stateMachine* machine;
    state* stateObj;
    exitCondition* condition;
    //exitAction* action;
    reader.readNextStartElement();
    this->_currentConceptualModel=new ConceptualModelDefinition();
    while((reader.name()!="conceptualModelDefinition" ) &&  (!reader.atEnd()))
    {   //Q_ASSERT(reader.name());

        if(reader.name()=="stateMachine")
        {
            reader.readNextStartElement();
            if(reader.name()=="name")
            {
                nameofstateMachine=reader.readElementText();
                this->_currentStateMachine= new stateMachine(nameofstateMachine);

                this->_currentConceptualModel->SetStateMachine(this->_currentStateMachine);

            }

        }
        if(reader.name()=="conceptualEntity")
        {
            reader.readNext();
        }

        if(reader.name()=="state")
        {
            reader.readNextStartElement();

            if (reader.name()=="name")
            {
                stateName=reader.readElementText();
                stateObj= new state(stateName);
                this->_currentStateMachine->AddState(stateObj);
                reader.readNextStartElement();
            }

        }

        if (reader.name()=="exitCondition")
        {
            condition= new exitCondition();
            reader.readNextStartElement();
            stateObj->SetExitCondition(condition);
         }
        if (reader.name()=="exitAction")
        {

            QString exitActiontxt=reader.readElementText();
            condition->SetExitAction(exitActiontxt);
            reader.readNextStartElement();

        }
        if (reader.name()=="nextState")
        {
            QString nextStatetxt=reader.readElementText();
            condition->SetNextState(nextStatetxt);

        }

        //addition
        if (reader.name()=="Interfaces")
        {
            //continue;
            reader.readNextStartElement();
        }
        if(reader.name()=="Interface")
        {
            QList<Interface*> interfacesList= this->ReadInterfaces();

            foreach(Interface* supportedInf,interfacesList)
            {
                this->_currentBOMObject->AddInterface(supportedInf);
            }
        }
        //addition end

        reader.readNext();
    }
    return this->_currentConceptualModel;
}

BOMObject* BOMAdaptationReader::GetBOMObject()
{
    return this->_currentBOMObject;
}
