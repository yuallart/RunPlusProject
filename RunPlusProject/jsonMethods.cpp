/**
 *  Copyright(c) 2022 Corporation.All rights reserved.
 * ┌──────────────────────────────────┐
 * │　\author: Yuallart
 * │　\version: 1.0.0
 * │  \saying: 不经一番寒彻骨，怎得梅花扑鼻香
 * │  \deprecated: The project must be described...
 * └──────────────────────────────────┘
 */

#include "JsonMethods.h"

JsonMethods::JsonMethods(int indent)
{
    this->indent = indent;
}

std::string JsonMethods::outputJsonStr(const nlohmann::json& jsonStr) const
{
    return jsonStr.dump(indent);
}

std::string JsonMethods::outputJsonStr(const std::string& jsonStr) const
{
    const json str = nlohmann::json::parse(jsonStr);
    return str.dump(indent);
}

std::string JsonMethods::outputJsonStr(const char* jsonStr) const
{
    const json str = nlohmann::json::parse(jsonStr);
    return str.dump(indent);
}

nlohmann::json JsonMethods::outputJsonData(const QString& jsonStr) const
{
    return json::parse(jsonStr.toStdString());
}

nlohmann::json JsonMethods::outputJsonData(const QByteArray& jsonStr) const
{
    return json::parse(jsonStr.data());
}
