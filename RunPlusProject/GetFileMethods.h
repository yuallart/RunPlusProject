#pragma once
#include <qdir.h>
#include <QDebug>
#include <QJsonObject>

/**
 * \brief �ļ�������
 */
class GetFileMethods
{
private:
    /**
     * \brief ���ڱ����ȡ�����ļ��б���Ϣ
     */
    QFileInfoList globalFileList;
public:
    /**
     * \brief �˺������ڻ�ȡָ���ļ�·���µ������ļ���ֻ�����ļ�
     * \param filePath ����һ��Ŀ¼��ַ�ַ���
     * \param fileList ����һ��list��ַ
     * \return �����ļ��б�ĳ���
     */
    int GetFileInfo(const char* filePath, QFileInfoList* fileList)
    {
        //QDir��·��һ��Ҫ��ȫ·�������·�����д���
        QDir dir(QString::fromLocal8Bit(filePath));
        if (!dir.exists())
        {
            return -1;
        }
        dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
        dir.setSorting(QDir::DirsFirst);
        //ָ��һ��list
        *fileList = dir.entryInfoList();
        globalFileList = dir.entryInfoList();
        return fileList->length();
    }
    /**
     * @brief ����ȡ�����ļ���Ϣת��Ϊ�б�
     * @return ����һ��JSON����
     */
    QJsonObject toJsonList()
    {
        QJsonObject json;
        foreach(QFileInfo fileInfo, globalFileList)
        {
            json.insert(fileInfo.fileName(), fileInfo.filePath());
        }
        return json;
    }
};
