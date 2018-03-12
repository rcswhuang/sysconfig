#include "hsysconfig.h"

HSysConfig::HSysConfig(QObject *parent) :
    QObject(parent)
{
    initSysSet();
}

HSysConfig::~HSysConfig()
{
    //析构函数

}

void HSysConfig::initSysSet()
{
    pSettingList = new HSettingList;

    pNormalSysSetList = new HSysSetList;//一般设置
    SETTING* normalSetting = new SETTING;
    normalSetting->wSettingId = SYS_SET_NORMAL;
    normalSetting->pSysSetList = pNormalSysSetList;
    pSettingList->append(normalSetting);

    pNetSysSetList = new HSysSetList;//网络设置
    SETTING* netSetting = new SETTING;
    netSetting->wSettingId = SYS_SET_NET;
    netSetting->pSysSetList = pNetSysSetList;
    pSettingList->append(netSetting);

    pPathSysSetList = new HSysSetList;//路径设置
    SETTING* pathSetting = new SETTING;
    pathSetting->wSettingId = SYS_SET_PATH;
    pathSetting->pSysSetList = pPathSysSetList;
    pSettingList->append(pathSetting);

    pFunSysSetList = new HSysSetList;//功能设置
    SETTING* funSetting = new SETTING;
    funSetting->wSettingId = SYS_SET_PATH;
    funSetting->pSysSetList = pFunSysSetList;
    pSettingList->append(funSetting);

    pFormatSysSetList = new HSysSetList;//票号格式设置
    SETTING* formatSetting = new SETTING;
    formatSetting->wSettingId = SYS_SET_FORMAT;
    formatSetting->pSysSetList = pFormatSysSetList;
    pSettingList->append(formatSetting);

    pTicketSysSetList = new HSysSetList;//操作票设置
    SETTING* ticketSetting = new SETTING;
    ticketSetting->wSettingId = SYS_SET_TICKET;
    ticketSetting->pSysSetList = pTicketSysSetList;
    pSettingList->append(ticketSetting);

    pOtherSysSetList = new HSysSetList;//其他设置
    SETTING* otherSetting = new SETTING;
    otherSetting->wSettingId = SYS_SET_OTHER;
    otherSetting->pSysSetList = pOtherSysSetList;
    pSettingList->append(otherSetting);

    pXml = new HXML(this);
    //pXml->parseXML();
}

void HSysConfig::loadSysSet(HSysSetList* &pSysSetList, ushort wSettingId)
{
    //先调用xml接口去加载配置
    //再调用界面接口将配置传给界面部分供显示
}

void HSysConfig::saveSysSet(HSysSetList* &pSysSetList, ushort wSettingId)
{
    //先调用界面接口将界面信息保存
    //再调用xml接口将配置保存
}







