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
    }

    void cleanupTestCase()
    {
    }

    /**
     * \brief 测试方法
     */
    void outputJsonStr()
    {
        JsonMethods jsonMethods;
        std::string jsonStr = jsonMethods.outputJsonStr(u8R"({"name":"小明"})");
        std::cout << jsonStr << std::endl;
    }
};
