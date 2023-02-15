#pragma once
#include <iostream>
#include <QObject>
#include <ReadFile.h>

class ReadFileTest : public QObject
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

    void readFileDataTest()
    {
        ReadFile readFile;
        QString fileText = readFile.readFileData(QString(R"(C:\Users\Administrator\Desktop\QSS.md)"));
        qDebug() << fileText;
    }
};
