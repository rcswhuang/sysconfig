//#ifndef HSYSCONFIG_H
//#define HSYSCONFIG_H

#include <QObject>
#include <QWidget>
#include <QVariant>
#include <QList>
#include "hxml.h"
#include "sysconfigapi.h"

class HSysConfig : public QObject
{
    Q_OBJECT
public:
    explicit HSysConfig(QObject *parent = 0);
    ~HSysConfig();
public:
    void initSysSet();
    void loadSysSet(HSysSetList* &pSysSetList,ushort wSettingId);
    void saveSysSet(HSysSetList* &pSysSetList,ushort wSettingId);
public:
    HXML *pXml;
    HSettingList* pSettingList;
    HSysSetList* pNormalSysSetList;//一般设置
    HSysSetList* pNetSysSetList;//网络设置
    HSysSetList* pPathSysSetList;//路径设置
    HSysSetList* pFunSysSetList;//功能设置
    HSysSetList* pFormatSysSetList;//票号格式设置
    HSysSetList* pTicketSysSetList;//操作票设置
    HSysSetList* pOtherSysSetList;//其他设置
signals:

public slots:

};

//#endif // HSYSCONFIG_H
