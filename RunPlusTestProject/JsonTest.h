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
#include "tchar.h"
#include <codecvt>
#include <QObject>
#include <QTest>
#include <iostream>
#include <nlohmann/json.hpp>
 /**
  * \brief JSON模块测试类
  */
class JsonTest : public QObject
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

    /**
     * \brief 测试方法
     */
    void outputJsonStr(){}
};
