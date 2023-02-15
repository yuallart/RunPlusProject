#pragma once
#include <iostream>
#include <QObject>
#include <GetFileInfo.h>

class GetFileInfoTest : public QObject
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

    void test()
    {
        GetFileInfo* getFileInfo = new GetFileInfo();
        bool result = getFileInfo->isDirExist(R"(C:\Users\Administrator\Desktop\NoteFolder)");
        std::cout << result << std::endl;
    }
};
