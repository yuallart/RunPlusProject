#pragma once
#include <iostream>
#include <QTextCodec>

class EncodingForm
{
public:
    std::string encodingToGBK(const std::string& target) const
    {
        const QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
        const QString str = utf8->toUnicode(target.c_str());
        return str.toLocal8Bit().toStdString();
    }

    std::string encodingToGBK(const char* target) const
    {
        const QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
        const QString str = utf8->toUnicode(target);
        return str.toLocal8Bit().toStdString();
    }
};
