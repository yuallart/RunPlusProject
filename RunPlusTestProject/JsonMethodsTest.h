﻿/**
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
#include <JsonMethods.h>
#include <iostream>
#include <nlohmann/json.hpp>
 /**
  * \brief JSON模块测试类
  */
class JsonMethodsTest : public QObject
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
    void outputJsonStr()
    {
        JsonMethods jsonMethods;
        const auto firstJsonStr = jsonMethods.outputJsonStr(u8R"({"name":"小明"})");
        const auto secondJsonStr = jsonMethods.outputJsonStr(std::string(u8R"({"gender":"男"})"));
        const auto thirdJsonStr = jsonMethods.outputJsonStr(nlohmann::json{ "work",u8"程序员" });
        std::cout << firstJsonStr << std::endl;
        std::cout << secondJsonStr << std::endl;
        std::cout << thirdJsonStr << std::endl;
    }
};
