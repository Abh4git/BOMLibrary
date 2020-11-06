#include "bomlibrary.h"


 bool BOMLibrary:: LoadDefinitions(QString relativeFolderName)
	{
		bool loaded=false;
		QDir dir(relativeFolderName+ "/");
		QStringList filters("*.xml");
		QFileInfoList fileList= dir.entryInfoList(filters);
		foreach(QFileInfo devfileInfo, fileList)
		{
        BOMAdaptationReader* readerToParseBOMDef=new BOMAdaptationReader(devfileInfo.fileName());
		readerToParseBOMDef->SetDirectory(relativeFolderName +  "/");
        readerToParseBOMDef->ReadDefintions();
        m_currentDefintions.append(readerToParseBOMDef->GetBOMObject());
		loaded=true;
		}
		return loaded;
	}
	
 BOMObject* BOMLibrary::FindBOMType(QString BOMTypeName)
	{
    foreach(BOMObject* bomType,  this->m_currentDefintions)
    {
        if (bomType->GetModelIdentification()->GetName()==BOMTypeName)
        {
            return bomType;
        }
    }
}

 Q_PLUGIN_METADATA(BOMLIBRARY_LIB::BOMLibrary)
//Q_EXPORT_PLUGIN2(BOMLIBRARY_LIB, BOMLibrary)
