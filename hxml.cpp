#include "hxml.h"
#include <QFile>
#include "hsysconfig.h"
HXML::HXML(HSysConfig* sysconfig)
    :pSysConfig(sysconfig)
{

}

HXML::~HXML()
{

}

/*
<SYSCONFIG  NAME=”sysconfig”>
    <SETTING ID="SYS_SET_NET">
        <PARAMETER OBJNAME="" NAME=”com select” VALUE=”com1” />
        <PARAMETER NAME=”com set” VALUE=”9600,n,8,1” />
        ....

        <PARAMETER …../>
   </SETTING>
   <SETTING ID = "SYS_SET_NORMAL">
       ....
   </SETTING>
   ...
</SYSCONFIG>
*/
void HXML::parseXML()
{
    QDomDocument doc;
    QFile file(strConfigFile);
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    // print out the element names of all elements that are direct children
    // of the outermost element.
    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();//SETTING
    while(!n.isNull()) {
        if(!n.hasAttributes())
            continue;
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull())
        {
            QString strId;
            e.attribute("ID",strId);
            int wSettingID = strId.toUShort();
            if(pSysConfig->pSettingList == NULL)
                return;
            HSysSetList* pSysSetList = NULL;
            if(wSettingID == SYS_SET_NET)
            {
               if(pSysConfig->pNetSysSetList)
                   pSysSetList = pSysConfig->pNetSysSetList;

            }
            else if(wSettingID == SYS_SET_NORMAL)
            {
                if(pSysConfig->pNormalSysSetList)
                    pSysSetList = pSysConfig->pNormalSysSetList;
            }
            else if(wSettingID ==SYS_SET_FUN )
            {
                if(pSysConfig->pFunSysSetList)
                    pSysSetList = pSysConfig->pFunSysSetList;
            }
            else if(wSettingID ==SYS_SET_PATH )
            {
                if(pSysConfig->pPathSysSetList)
                    pSysSetList = pSysConfig->pPathSysSetList;
            }
            else if(wSettingID ==SYS_SET_TICKET)
            {
                if(pSysConfig->pTicketSysSetList)
                    pSysSetList = pSysConfig->pTicketSysSetList;
            }
            else if(wSettingID ==SYS_SET_FORMAT )
            {
                if(pSysConfig->pFormatSysSetList)
                    pSysSetList = pSysConfig->pFormatSysSetList;
            }
            else if(wSettingID ==SYS_SET_OTHER )
            {
                if(pSysConfig->pOtherSysSetList)
                    pSysSetList = pSysConfig->pOtherSysSetList;
            }
            parseDomNode(n,pSysSetList);
        }
        n = n.nextSibling();
    }

}

void HXML::parseDomNode(const QDomNode& dom,HSysSetList* pList)
{
    //SETTING* setting;// = findSettingById(id);
    if(pList == NULL)
        return;
    QDomNode n = dom.firstChild();//PARAM
    while(!n.isNull())
    {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull())
        {
            if(e.tagName() == "PARAMETER")
            {
                SYSSET* sysSet = new SYSSET;
                if(sysSet)
                {
                    QString strId;
                    e.attribute("ID",strId);
                    sysSet->id = strId.toUShort();
                    QString strValue;
                    e.attribute("VALUE",strValue);
                    sysSet->var = QVariant(strValue);
                    pList->append(sysSet);
                }
            }
        }
        n = n.nextSibling();
    }
}




void HXML::writeXML()
{
    QDomDocument doc("MyML");
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml" , "version =\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement("SYSCONFIG");
    doc.appendChild(root);

    for(int i = 0; i < pSysConfig->pSettingList->count();i++)
    {
        SETTING* setting = (SETTING*)pSysConfig->pSettingList->at(i);
        if(setting)
        {
            QDomElement setDom = doc.createElement("SETTING");
            QDomAttr idAttr = doc.createAttribute("ID");
            idAttr.setValue(QString("%1").arg(setting->wSettingId));
            setDom.setAttributeNode(idAttr);
            root.appendChild(setDom);
            writeDomNode(doc,root,setting->pSysSetList);
        }
    }
}

void HXML::writeDomNode(QDomDocument &doc,QDomElement& root, HSysSetList* &pSysSetList)
{
    if(pSysSetList == NULL)
        return;
    for(int i = 0; i < pSysSetList->count();i++)
    {
        SYSSET* sysSet = (SYSSET*)pSysSetList->at(i);
        if(sysSet)
        {
            QDomElement dom = doc.createElement("PARAMETER");
            dom.setAttribute("ID",sysSet->id);
            dom.setAttribute("VALUE",sysSet->var.toString());
            root.appendChild(dom);
        }
    }
}


void HXML::loadSysSet(HSettingList* &sysSetList)
{
    //pSysSetList = sysSetList;
    //parseXML();
}

void HXML::saveSysSet(HSettingList* &sysSetList)
{
    //pSysSetList = sysSetList;
    //writeXML();
}
