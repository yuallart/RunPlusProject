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
#include <qtestcase.h>
#include "ReadFileTest.h"
#include "GetFileInfoTest.h"

class mainTest
{
public:
    void readFileObjectTest() const
    {
        ReadFileTest readFileTest;
        QTest::qExec(&readFileTest);
    }

    void getFileInfoFunTest() const
    {
        GetFileInfoTest getFileInfo;
        QTest::qExec(&getFileInfo);
    }
};
