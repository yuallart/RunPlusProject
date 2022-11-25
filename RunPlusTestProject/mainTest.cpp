/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...　　　　　　　　　　　　
 * └──────────────────────────────────┘
 */

#include "mainTest.h"

void mainTest::jsonMethods() const
{
    JsonMethodsTest jsonMethodsTest;
    QTest::qExec(&jsonMethodsTest);
}

void mainTest::getFileMethods() const
{
    GetFileMethodsTest getFileMethodsTest;
    QTest::qExec(&getFileMethodsTest);
}

void main()
{
    const mainTest test;
    test.jsonMethods();
    test.getFileMethods();
    char a = getchar();
}
