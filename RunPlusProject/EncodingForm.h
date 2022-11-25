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
