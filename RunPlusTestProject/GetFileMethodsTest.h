/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...　　　　　　　　　　　　
 * └──────────────────────────────────┘
 */
#pragma once
#include <iostream>
#include <QObject>
#include <GetFileMethods.h>
#include <qobjectdefs.h>
#include <JsonMethods.h>
#include <nlohmann/json.hpp>

class GetFileMethodsTest : public QObject
{
    Q_OBJECT
public:
    GetFileMethods getFileMethods;
    JsonMethods jsonMethods;
private slots:
    void initTestCase()
    {
        std::cout << "\n==========>\n" << std::endl;
    }

    void cleanupTestCase()
    {
        std::cout << "\n==========>\n" << std::endl;
    }

    void toJsonListTest()
    {
        nlohmann::json* fileInfoJson = getFileMethods.getFileInfo(R"(C:\Users\ShortcutFolder)")
                                                     .toInfoJson()
                                                     .getFileInfoJson();
        std::string fileInfoStr = jsonMethods.outputJsonStr(*fileInfoJson);
        std::cout << fileInfoStr << std::endl;
    }

    void getFileTextTest()
    {
        QString fileName = R"(C:\Users\Administrator\Desktop\text.json)";
        QString text;
        QString error = getFileMethods.getFileText(fileName, text);
        qDebug() << error;
        qDebug() << text;
    }
};
