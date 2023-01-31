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
#include <QTextCodec>
#include <QFile>
#include <QTextStream>

/**
 * \brief 编码转换类
 */
class EncodingMethods
{
public:
    QString encodingToGBK(const std::string& target) const
    {
        const QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
        const QString str = utf8->toUnicode(target.c_str());
        return str.toLocal8Bit();
    }

    QString encodingToGBK(const char* target) const
    {
        const QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
        const QString str = utf8->toUnicode(target);
        return str.toLocal8Bit();
    }

    QString encodingToGBK(const QByteArray& target) const
    {
        const QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
        const QString str = utf8->toUnicode(target);
        return str.toLocal8Bit();
    }

    QString encodingUtf8(const char* target) const
    {
        const QTextCodec* gbk = QTextCodec::codecForName("GB2312");
        const QString str = gbk->toUnicode(target);
        return str.toUtf8();
    }

    QString encodingUtf8(const std::string& target) const
    {
        const QTextCodec* gbk = QTextCodec::codecForName("GB2312");
        const QString str = gbk->toUnicode(target.c_str());
        return str.toUtf8();
    }
};
