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
        GetFileMethods getFile;
        QFileInfoList fileInfo;
        getFile.GetFileInfo(R"(../)", &fileInfo);
        nlohmann::json jsonStr = getFile.toJsonList(&fileInfo);
        JsonMethods json;
        std::string resultStr = json.outputJsonStr(jsonStr);
        std::cout << resultStr << std::endl;
    }
};
