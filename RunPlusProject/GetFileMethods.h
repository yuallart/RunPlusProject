#pragma once
#include <qdir.h>
#include <QDebug>
#include <nlohmann/json.hpp>

/**
 * \brief 文件处理类
 */
class GetFileMethods
{
private:
public:
    /**
     * \brief 此函数用于获取指定文件路径下的所有文件，只检索文件
     * \param filePath 接收一个目录地址字符串
     * \param fileList 接收一个list地址
     * \return 返回文件列表的长度
     */
    int GetFileInfo(const char* filePath, QFileInfoList* fileList)
    {
        //QDir的路径一定要是全路径，相对路径会有错误
        QDir dir(QString::fromLocal8Bit(filePath));
        if (!dir.exists())
        {
            return -1;
        }
        dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
        dir.setSorting(QDir::DirsFirst);
        //指向一个list
        *fileList = dir.entryInfoList();
        return fileList->length();
    }

    /**
     * @brief 将获取到的文件信息转化为列表
     * @return 返回一个JSON对象
     */
    nlohmann::json toJsonList(QFileInfoList fileList)
    {
        std::map<std::string, std::string> fileInfo;
        for (QFileInfoList::iterator iterator = fileList.begin(); iterator != fileList.end(); ++iterator)
        {
            std::string fileName = iterator.i->t().fileName().toStdString();
            std::string filePath = iterator.i->t().filePath().toStdString();
            fileInfo.insert(std::make_pair(fileName, filePath));
        }
        return nlohmann::json(fileInfo);
    }
};
