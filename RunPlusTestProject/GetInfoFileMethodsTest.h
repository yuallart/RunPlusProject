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
#include <GetFileInfoMethods.h>
#include <qobjectdefs.h>
#include <JsonMethods.h>

class GetInfoFileMethodsTest : public QObject
{
    Q_OBJECT
public:
    GetFileInfoMethods getFileInfo;
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
        nlohmann::json* fileInfoJson = getFileInfo
                                       .getFileInfo(R"(C:\Users\ShortcutFolder)")
                                       .toInfoJson()
                                       .getFileInfoJson();
        std::string fileInfoStr = jsonMethods.outputJsonStr(*fileInfoJson);
        std::cout << fileInfoStr << std::endl;
    }
};
