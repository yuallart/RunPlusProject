#pragma once
#include <iostream>
#include <QObject>
#include <PutFileMethods.h>

class PutFileMethodsTest : public QObject
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

    void writeFileTest()
    {
        PutFileMethods putFile;
        putFile.writeFile(
            R"(C:\Users\Yuallart\Desktop\test.txt)",
            "这是一段话,\n也是一段祝福"
        );
    }
};
