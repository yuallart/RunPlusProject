#pragma once
#include <QProcess>

class ExecuteProcess
{
public:
    void execute(QByteArray command)
    {
        QProcess process;
        process.start(command);
        process.waitForStarted();
        process.waitForFinished();
    }
};
