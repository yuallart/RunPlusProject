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
#include "CodingParse.h"
#include "WriteFile.h"
using json = nlohmann::json;

/**
 * \brief JSON转换类
 */
class JsonParse : public CodingParse
{
private:
    int indent = 2;
    std::string jsonText;
    json jsonData;
public:
    explicit JsonParse(int indent): indent(indent)
    {
    }

    int getIndent() const
    {
        return indent;
    }

    json getJsonData() const
    {
        return jsonData;
    }

    std::string getJsonText() const
    {
        return jsonText;
    }

    JsonParse() = default;
    /**
     * 此方法请使用UTF-8的默认编码
     * \brief 生成JSON字符串方法
     * \param jsonData 接收一个json对象
     * \return 返回一个json格式string字符串
     */
    JsonParse& outputJsonData(const nlohmann::json& jsonData)
    {
        this->jsonData = jsonData;
        jsonText = jsonData.dump(indent);
        return *this;
    }

    JsonParse& outputJsonData(const QString& jsonStr)
    {
        jsonData = json::parse(jsonStr.toStdString());
        jsonText = jsonData.dump(indent);
        return *this;
    }

    JsonParse& outputJsonData(const QByteArray& jsonStr)
    {
        jsonData = json::parse(jsonStr.toStdString());
        jsonText = jsonData.dump(indent);
        return *this;
    }
};
