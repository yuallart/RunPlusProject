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
#include <nlohmann/json.hpp>
#include "EncodingMethods.h"
using json = nlohmann::json;

/**
 * \brief JSON转换类
 */
class JsonMethods : public EncodingMethods
{
private:
    int indent = 2;
public:
    explicit JsonMethods(int indent = 2);

    /**
     * 此方法请使用UTF-8的默认编码
     * \brief 生成JSON字符串方法
     * \param jsonStr 接收一个json对象
     * \return 返回一个json格式string字符串
     */
    std::string outputJsonStr(const nlohmann::json& jsonStr) const;

    std::string outputJsonStr(const std::string& jsonStr) const;

    std::string outputJsonStr(const char* jsonStr) const;

    nlohmann::json outputJsonData(const QString& jsonStr) const;

    nlohmann::json outputJsonData(const QByteArray& jsonStr) const;
};
