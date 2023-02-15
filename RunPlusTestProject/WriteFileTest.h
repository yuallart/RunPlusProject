#pragma once
#include <iostream>
#include <QObject>

class WriteFileTest : public QObject
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
       
    }
};
